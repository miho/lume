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

#pragma once

namespace lume
{

template <class T>
class TemporaryArithmeticTuple;

template <class T>
class ArithmeticTuple
{
public:
    using value_type = T;

    ArithmeticTuple () = delete;
    ArithmeticTuple (ArithmeticTuple const&) = delete;

    ArithmeticTuple (T* data, size_t size)
        : m_data (data)
        , m_size (size)
    {
    }

    ArithmeticTuple& operator = (ArithmeticTuple const& v)
    {
        assert (m_size == v.size ());
        for(size_t i = 0; i < m_size; ++i) {
            m_data [i] = v.m_data [i];
        }
        return *this;
    }

    ArithmeticTuple& operator = (TemporaryArithmeticTuple <T> const& v)
    {
        assert (m_size == v.size ());
        for(size_t i = 0; i < m_size; ++i) {
            m_data [i] = v [i];
        }
        return *this;
    }

    bool operator == (ArithmeticTuple const& v)
    {
        assert (m_size == v.size ());

        for(size_t i = 0; i < m_size; ++i) {
            if (m_data [i] != v.m_data [i]) {
                return false;
            }
        }

        return true;
    }

    bool operator != (ArithmeticTuple const& v)
    {
        return ! (*this == v);
    }

    size_t size () const                    {return m_size;}

    T& operator [] (size_t const i)         {return m_data [i];}
    T  operator [] (size_t const i) const   {return m_data [i];}

    T*       data ()                        {return m_data;}
    T const* data () const                  {return m_data;}

private:
    T*     m_data;
    size_t m_size;
};

template <class T>
class TemporaryArithmeticTuple
{
public:
    using value_type = T;
    
    TemporaryArithmeticTuple (size_t s)
        : m_size (s)
    {
        assert (s <= m_maxSize);
    }

    TemporaryArithmeticTuple& operator = (TemporaryArithmeticTuple <T> const& v)
    {
        assert (m_size == v.size ());
        for(size_t i = 0; i < m_size; ++i) {
            m_data [i] = v.m_data [i];
        }
        return *this;
    }

    size_t size () const                    {return m_size;}

    T& operator [] (size_t const i)         {return m_data [i];}
    T  operator [] (size_t const i) const   {return m_data [i];}

    T*       data ()                        {return m_data;}
    T const* data () const                  {return m_data;}

private:
    static constexpr size_t s_maxSize = 4;
    T      m_data [s_maxSize];
    size_t m_size;
};

template <class Tuple>
TemporaryArithmeticTuple <typename Tuple::value_type>
operator + (Tuple const& a, Tuple const& b)
{
    assert (a.size () == b.size ());
    TemporaryArithmeticTuple <typename Tuple::value_type> r (a.size ());
    for(size_t i = 0; i < a.size (); ++i) {
        r [i] = a[i] + b[i];
    }
    return r;
}

template <class Tuple>
TemporaryArithmeticTuple <typename Tuple::value_type>
operator * (const typename Tuple::value_type s, Tuple const& a)
{
    TemporaryArithmeticTuple <typename Tuple::value_type> r (a.size ());
    for(size_t i = 0; i < a.size (); ++i) {
        r [i] = s * a[i];
    }
    return r;
}

template <class Tuple>
TemporaryArithmeticTuple <typename Tuple::value_type>
operator * (Tuple const& a, const typename Tuple::value_type s)
{
    return s * a;
}

}// end of namespace lume
