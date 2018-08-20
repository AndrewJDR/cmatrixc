cd mbedtls
make
cd ..
gcc -gstabs -DUSE_MBEDTLS -I. -o matrixc_test client.c mbedtls/libmbedtls.a mbedtls/libmbedx509.a mbedtls/libmbedcrypto.a
