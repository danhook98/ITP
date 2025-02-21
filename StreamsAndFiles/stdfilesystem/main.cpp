#include <iostream>
#include <filesystem>
#include <__msvc_filebuf.hpp>

/*
 * Loading individual files is all well and good, but it doesn't provide a way to deal with
 * the underlying file system.
 *
 * std::filesystem was introduced in C++17 to provide a cross-platform solution to dealing
 * with the underlying file system of the operating system. Rather than representing paths
 * to files and other assets as strings, the library offers a system that deals directly with
 * the OS to ensure we aren't making any horrific mistakes.
 *
 * Before diving into code, it's important to understand some definitions.
 *
 *     File - an object in the file system that holds data which can be read from or written
 *            to. They have names and attributes, one of the core attributes is their typr:
 *
 *                directory - a file that acts as a container of other files (which may also
 *                            be directories).
 *                regular file - a directory entry that hard links a name to an existing file.
 *                symbolic link - a directory entry that associates a name with a path which
 *                                may not exist.
 *
 *     File name - a string of characters that represents a file - validity is implementation
 *                 specific (and also depends on the OS).
 *
 *     Path - The sequence of elements that identifies a file, beginning with an optional root
 *            name (e.g. "C:\" or "//server" on Windows), followed by an optional root directory
 *            ("/" on Unix) and then followed by a sequence of zero or more file names. There are
 *            three types of path:
 *
 *            absolute - a path that unambiguously identifies the location of a file:
 *                       C:\Users\UserName\Documents\myfile.txt
 *            canonical - an absolute path that includes no symbolic links, or any relative
 *                        elements ("." or "..")
 *            relative - a path that identifies the location of a file relative to another location
 *                       on the file system. "." is a relative location for the current directory.
 *                       ".." is a relative signifier for the parent directory:
 *                       /../../OtherUser/
 *     Filesystem - The underlying structure that manages files and directories. In most modern
 *                  operating systems, these are represented as hierarchies.
 *
 * The file system library can be used to interact with these elements, specifically, we should use
 * it when we want to do any of the following:
 *
 *     - Iterate over files and directories.
 *     - Get information about files.
 *     - Compose, decompose, and compare paths.
 *     - Create, copy, and delete directories.
 *     - Copy and delete files.
 *
 * The filesystem library does not load files, we do that with the various input/output streams.
 */

// Everything that we need to work with the file system is available in the <filesystem> header.

int main()
{
    // The core class from filesystem that we're most likely to use is path. We can enter a path
    // as a string, the backslashes are escaped otherwise they'd be treated as special characters.
    std::filesystem::path testPath("P:\\repos\\Uni\\C++ Projects\\ITP\\test.txt");
    std::cout << testPath;

    return 0; 
}