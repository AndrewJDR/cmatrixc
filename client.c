#define HTTP_IMPLEMENTATION
#include "http.h"

int main(int argc, char** argv)
{
    (void) argc, argv;

    http_t* request = http_get( argv[1], NULL );
    if( !request )
    {
        printf( "Invalid request.\n" );
        return 1;
    }

    http_status_t status = HTTP_STATUS_PENDING;
    int prev_size = -1;
    while( status == HTTP_STATUS_PENDING )
    {
        status = http_process( request );
        if( prev_size != (int) request->response_size )
        {
            printf( "%d byte(s) received. prev_size:%d\n", (int) request->response_size, prev_size );
            prev_size = (int) request->response_size;
        }

    }

    if( status == HTTP_STATUS_FAILED )
    {
        printf( "HTTP request failed (%d): %s.\n", request->status_code, request->reason_phrase );
        http_release( request );
        return 1;
    }

    printf( "\nContent type: %s\n\n%s\n", request->content_type, (char const*)request->response_data );
    http_release( request );
    return 0;
}
