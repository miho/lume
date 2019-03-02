// This file is part of lume, a C++ library for lightweight unstructured meshes
//
// Copyright (C) 2018 Sebastian Reiter
// Copyright (C) 2018 G-CSC, Goethe University Frankfurt
// Author: Sebastian Reiter <s.b.reiter@gmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#ifndef __H__lume_custom_exception
#define __H__lume_custom_exception

#include <stdexcept>
#include <string>

///	Declares an exception class. baseClass should derive from std::exception or similar.
#define DECLARE_CUSTOM_EXCEPTION(className, baseClass) \
	class className : public baseClass {\
	public:\
		className () : baseClass ("") {setup_msg ("");}\
		className (const char* what) : baseClass ("") {setup_msg(what);}\
		className (const std::string& what) : baseClass ("") {setup_msg(what.c_str());}\
		const char* what () const noexcept override {return m_what.c_str();}\
        template <class T>\
        className& operator << (const T& t) {m_what.append (std::to_string (t)); return *this;}\
        className& operator << (const std::string& t) {m_what.append (t); return *this;}\
        className& operator << (const char* t) {m_what.append (t); return *this;}\
	private:\
		void setup_msg (const char* what) {m_what.append (#className).append (": ").append (what);}\
		std::string	m_what;\
	}; 
	
namespace lume {

/// The base class for all exceptions thrown by slimesh
DECLARE_CUSTOM_EXCEPTION (LumeError, std::runtime_error);

}//	end of namespace lume

#endif	//__H__lume_custom_exception
