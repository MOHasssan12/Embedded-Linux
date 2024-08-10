# Creating Recipe

Before writing a recipe we should introduce some information first about recipe Variables 

In Yocto, recipes are essential components that describe how to build and package software. Here’s a detailed breakdown of key concepts and variables involved in writing and understanding a recipe.
Key Variables in a Recipe

##    Basic Recipe Variables
SUMMARY: A brief description of what the recipe does.
DESCRIPTION: A more detailed description of the recipe.
LICENSE: Specifies the license under which the software is distributed (e.g., MIT, GPL).
LIC_FILES_CHKSUM: The checksum for the license file to ensure it matches the expected content. Required if LICENSE is set to something other than "closed".

Example:

```sh
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=hash"
```

Source Retrieval and Location

SRC_URI: This variable specifies where to fetch the source files from. It can use different **schemas** depending on the source location:
file:: Local files on the machine.
git:: Git repositories (supports ssh or https protocols).
https:: Files from an HTTP server.

Example:

`SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"`

SRC_REV: Used with Git to specify a particular commit hash to check out.

Example:

`SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"`

Hidden Local Variables

hidden local variables that is set by bitbake 

    S: The source directory where the source code is unpacked. Default is ${WORKDIR}/git.
    D: The destination directory where the package files are installed. It’s used by the package feed to build the final output.
    B: The build directory where the compilation happens. Default is ${WORKDIR}/build.

To see the values of these variables, you can use:

```sh
bitbake -e recipe | grep ^S=
bitbake -e recipe | grep ^B=
bitbake -e recipe | grep ^D=
```
Version and Release

    PV: The version of the package (e.g., 2.0).
    PR: The release number, which increments for updates or fixes to the version (e.g., r3).
    PN: recipe name 
Recipe naming convention:

`myrecipe_2.0_r3.bb`

**Version**: Represents the actual version of the software.
**Release**: Represents the number of times the version has been released, often used for fixes or updates.

## How Bitbake Processes a Recipe

*    Fetching:
    Bitbake fetches the source files as specified by SRC_URI. These files are placed in the downloads directory. When using Git, it clones the repository into the WORKDIR.

*    Unpacking:
    The fetched source is unpacked into the S directory. For example, if SRC_URI is a Git repository, it will be checked out into ${WORKDIR}/git.

*    Building:
    The build process takes place in the B directory. Bitbake uses the information from the recipe and the cmake class to configure, compile, and link the software.

*    Installation:
    The built files are installed into the D directory, which is later used to package the software.

*    Python Commands and Hidden Variables:
    Bitbake converts the recipe into Python commands. During this process, it sets up hidden variables and paths that are used internally for building and packaging.


There is two important files that contain all used variables and tasks by bitbake 

1) documentation.conf
2) bitbake.conf


## Build recipe

```sh
SUMMARY = "meta -iti layers recipe"
DESCRIPTION = "Recipe created "

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"

S = "${WORKDIR}/git"
inherit cmake

# Ensure static library linking
EXTRA_OEMAKE = "STATIC_BUILD=1"

do_configure() {
    cmake -S ${S} -B ${B} \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_EXE_LINKER_FLAGS="-static" \
        -DBUILD_SHARED_LIBS=OFF
}

do_compile() {
    cd ${B}
    make
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/calculator ${D}${bindir}
}

```

### Recipe Overview
```
SUMMARY = "meta -iti layers recipe"
DESCRIPTION = "Recipe created "
```

`SUMMARY`: Provides a short summary of the recipe. This should be a brief description of what the recipe does.

`DESCRIPTION`: Provides a more detailed description of the recipe. This is optional but helpful for providing context about what the recipe builds.

### License Information
```
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
```
`LICENSE`: Specifies the license under which the software is distributed. Here, it's "MIT".
`LIC_FILES_CHKSUM`: Provides a checksum for the license file to ensure that the correct license file is being used. This helps with license compliance checks.

### Source Code
```
SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
SRCREV = "720c663c5fd7246b4b42c5205d74db7d9784b5b2"
```
`SRC_URI`: Specifies the source location. Here, it’s a Git repository URL with protocol=https and branch=main. This tells Yocto where to fetch the source code from.`SRCREV`: Specifies the exact commit or revision to fetch from the Git repository. This ensures that you get the exact version of the code needed.

### Work Directory

`S = "${WORKDIR}/git"`

S: Sets the source directory for the build process. ${WORKDIR}/git is where the code is checked out.

### Inherit CMake

In Yocto, the inherit keyword is used in recipes to include and utilize classes that provide additional functionality or behavior. These classes can encapsulate common build logic, configuration, or tasks. By inheriting a class, a recipe gains access to the functions and variables defined in that class, which simplifies and standardizes the recipe creation process.
Inheriting CMake

When you use inherit cmake in a recipe, you are instructing Yocto to apply the functionality provided by the cmake class. Here’s what happens when you inherit cmake:

-    CMake Configuration:
        The cmake class automatically adds the necessary configuration steps for building a project using CMake. It sets up the do_configure task to run CMake with the correct parameters.
        It also handles setting up the environment for CMake to find the required dependencies and tools.

-    Build Environment:
        The cmake class sets environment variables and paths required for CMake to locate libraries, headers, and other build dependencies.
        It ensures that CMake is invoked in a way that is compatible with the Yocto build environment.

-    Task Functions:
        It provides default implementations of do_configure, do_compile, and do_install tasks tailored for CMake-based projects. You can override these functions in your recipe if you need to customize the build process.

-    Dependencies Handling:
        The cmake class manages dependencies by adding necessary libraries and tools to the build environment. This helps ensure that your project can find and link against the required components.

-    Standardization:
        By inheriting cmake, you follow a standard approach for CMake-based projects. This consistency helps with maintenance and ensures that recipes follow best practices.
### Build Configuration


`EXTRA_OEMAKE = "STATIC_BUILD=1"`

EXTRA_OEMAKE: Provides additional flags to the make command. In this case, STATIC_BUILD=1 might be a custom flag used by the make process. This line is optional and specific to how your build system handles additional make flags.

### Configure Step

```
do_configure() {
    cmake -S ${S} -B ${B} \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_EXE_LINKER_FLAGS="-static" \
        -DBUILD_SHARED_LIBS=OFF
}
```
`do_configure()`: This function is executed to configure the build system before compilation.
`cmake -S ${S} -B ${B}`: Runs CMake to configure the project. -S ${S} specifies the source directory, and -B ${B} specifies the build directory.
`-DCMAKE_BUILD_TYPE=Release`: Sets the build type to "Release" which typically enables optimizations and disables debugging information.
`-DCMAKE_EXE_LINKER_FLAGS="-static"`: Adds the -static flag to the linker to enforce static linking for the executable.
`-DBUILD_SHARED_LIBS=OFF`: Disables the building of shared libraries, forcing the build to use static libraries.

### Compile Step
```
do_compile() {
    cd ${B}
    make
}
```
`do_compile()`: This function is executed to compile the project.
`cd ${B}`: Changes to the build directory where CMake has configured the build environment.
`make`: Runs the make command to compile the project. By default, it will use the configurations set in the do_configure step.

### Install Step
```
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/calculator ${D}${bindir}
}
```
`do_install()`: This function is executed to install the compiled binaries and other files into the appropriate directories.
`install -d ${D}${bindir}`: Creates the target directory for the binary, if it doesn’t already exist. `${D}${bindir}` expands to the directory where binaries should be installed (usually /usr/bin).
`install -m 0755 ${B}/calculator ${D}${bindir}`: Copies the calculator executable from the build directory to the target directory. -m 0755 sets the permissions of the file to be readable and executable by everyone, and writable by the owner.

