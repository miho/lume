# lume &nbsp;&nbsp;&nbsp;&nbsp; [![Build Status](https://travis-ci.com/sreiter/lume.svg?branch=master)](https://travis-ci.com/sreiter/lume)
## Introduction
**lume** (**L**ightweight **U**nstructured **ME**shes) is a *BSD* licensed C++ library for the representation, modification and visualization of large unstructured hybrid meshes (or unstructured hybrid grids).

Featured element types are: *Vertices, Edges, Triangles, Quadrilaterals, Tetrahedra, Pyramids, Prisms, Hexahedra*.
The set of available element types is easily extensible.

By storing underlying data in large contiguous arrays, **lume** is especially suited for efficient iteration of mesh elements and associated data.

The underlying data format (e.g. position data, normal data, element indices), is also compatible to many other libraries, e.g., to *OpenGL*.

## Lumeview
**lumeview** provides cross platform realtime visualization of unstructured hybrid meshes. Its multithreaded design aims at fluid user interaction during all stages of the visualization.

## Building lume/lumeview as a stand-alone library
**lume** features a CMake based build system. Create a 'build' directory in the **lume** root folder and from that build directory execute, e.g.:

    cmake -DCMAKE_BUILD_TYPE=Release ..
    make -j

In addition to the **lume** library, the following executables will be build:

    lumeview
    lumeshell
    lumetests

## Building lume as a part of your project
To build **lume** as part of your project, simply adding the line
    
    add_subdirectory (lume)

to the CMakeLists.txt of your project. To link it to your target, please use the following line:

    target_link_libraries (YOUR_TARGET  lume)

Necessary include directories will be automatically added to your target.

## License
**lume** is licensed under a *2-clause BSD* license:

    Copyright (C) 2018 Sebastian Reiter <s.b.reiter@gmail.com>
    Copyright (C) 2018 G-CSC, Goethe University Frankfurt
    All rights reserved.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Please note that **lume** is deployed with the two open source libraries **rapidxml** (MIT license) and **stl_reader** (BSD license).
