#   libsimdpp
#   Copyright (C) 2013  Povilas Kanapickas tir5c3@yahoo.co.uk
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are met:
#
#   * Redistributions of source code must retain the above copyright notice,
#     this list of conditions and the following disclaimer.
#
#   * Redistributions in binary form must reproduce the above copyright notice,
#     this list of conditions and the following disclaimer in the documentation
#     and/or other materials provided with the distribution.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(PACKAGE_TAGNAME "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION}")
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/reference/Doxyfile.in
        ${CMAKE_CURRENT_BINARY_DIR}/reference/Doxyfile @ONLY
    )
    add_custom_target(doc ALL
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/reference/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/reference
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif()

install(DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/reference/"
    DESTINATION "${SIMDPP_DOCDIR}/"
)
