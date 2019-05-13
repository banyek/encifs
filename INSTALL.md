This document provides generic information for compiling EnciFS.

If you are looking for specific instructions for your operating system or distribution,
take a look at the **[wiki](https://github.com/vgough/encifs/wiki)**.

Compiling EnciFS
===============

EnciFS uses the CMake toolchain to create makefiles.

Quickest way to build and test EnciFS :

    ./build.sh

Or following are the detailed steps to build EnciFS:

    mkdir build
    cd build
    cmake ..
    make

Optional, but strongly recommended, is running the unit and integration
tests to verify that the generated binaries work as expected.  Unit
tests will run almost instantly:

    make unittests
    make test

Integration tests will take ~20 seconds to run and will mount an
encrypted filesystem and run tests on it:  
*running integration tests from root (or with sudo) will run additional ones*

    make integration

The compilation process creates two executables, encifs and encifsctl in
the encifs directory.  You can install to in a system directory via:

    make install

If the default path (`/usr/local`) is not where you want things
installed, then set the CMAKE_INSTALL_PREFIX option when running cmake.  Eg:

    cmake .. -DCMAKE_INSTALL_PREFIX=/opt/local

Encifs and encifsctl can also be installed by hand.  They need no special
permissions.  You may also want the man pages encifs.1 and encifsctl.1.

Dependencies
============

EnciFS depends on a number of libraries:

    * fuse                   : the userspace filesystem layer
    * openssl / libressl     : used for cryptographic primitives
    * tinyxml2 (embeded)     : for reading and writing XML configuration files
    * gettext                : internationalization support
    * libintl                : internationalization support
    * cmake                  : version 3.0.2 (Debian jessie version) or newer
    * GNU make / ninja-build : to run the build for cmake
