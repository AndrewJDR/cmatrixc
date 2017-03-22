Matrix client library written in C.

Work in progress, not functional yet.

== Priorities
* The top priority is ease of developer usage: All code needed to build the library will be included in this project (\*)
* Provide control over memory allocation i.e. Overridable malloc/free.
* Low memory usage, could be used for embedded applications.
* Non-blocking; Can be run as part of main thread in an existing event loop (e.g. a game loop).
* Multi-platform - Linux, Windows, OS X, and probably most posix platforms.

\* Apart from a C standard library already provided with your compiler and the standard socket library already provided by your kernel/OS.
