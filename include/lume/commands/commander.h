// This file is part of lume, a C++ library for lightweight unstructured meshes
//
// Copyright (C) 2019 Sebastian Reiter <s.b.reiter@gmail.com>
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

#ifndef __H__lume_commander
#define __H__lume_commander

#include <map>
#include "lume/custom_exception.h"
#include "lume/commands/arguments.h"
#include "lume/commands/command.h"

namespace lume {
namespace commands {

DECLARE_CUSTOM_EXCEPTION (CommandExecutionError, LumeError);

class Commander
{
public:
    // template <class T, class ... Args>
    // void add (std::string name, Args&& args...)
    // {
    //     m_commands.emplace (std::move (name), std::make_unique <T> (std::forward <Args> (args)...));
    // }

    template <class T>
    void add (std::string name)
    {
        m_commands.emplace (std::move (name), std::make_unique <T> ());
    }

    // void run (const std::string& name, const Arguments& args)
    // {
    //     m_commands.at (name)->execute (args);
    // }

    void run (const std::string& name)
    {
        std::vector <ArgumentDesc> argDescs;
        std::vector <Variant>      argValues;

        try {
            m_commands.at (name)->execute (Arguments::create (argDescs, argValues));
        }
        catch (std::runtime_error& err)
        {
            throw CommandExecutionError () << "An error occurred during execution of command '"
                                           << name << "':\n" << "  -> " << err.what ();
        }
    }

private:
    std::map <std::string, std::unique_ptr <Command>> m_commands;
};

}// end of namespace commands
}// end of namespace lume

#endif    //__H__lume_commander