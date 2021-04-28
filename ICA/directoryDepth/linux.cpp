/**
 * @file linux.cpp
 *
 * @brief Provides the getExePath() function for linux machines
 *
 * @author Matt Wenger
 */
 #include <string>
 #include <limits.h>
 #include <unistd.h>

 // Returns the path of the exectuable file
 std::string getExePath() {
   char result[ PATH_MAX ];
   ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
   return std::string( result, (count > 0) ? count : 0 );
 }
