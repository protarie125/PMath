#pragma once
#include "../PMathCpp/Vector2i.h"

using namespace System;

namespace PMathDotnet {
    public ref class Vector2i
    {
    private:
        ahs::Vector2i* _native;
    public:
        Vector2i();
        Vector2i(Int32 v0, Int32 v1);
        !Vector2i();

    public: // operator
        static Vector2i^ operator+(Vector2i^ v);
        static Vector2i^ operator-(Vector2i^ v);
        static Vector2i^ operator+(Vector2i^ lhs, Vector2i^ rhs);
        static Vector2i^ operator-(Vector2i^ lhs, Vector2i^ rhs);
        static Vector2i^ operator*(Vector2i^ v, Int32 n);
        static Vector2i^ operator*(Int32 n, Vector2i^ v);

    public:
        virtual Int32 Dot(Vector2i^ other);
        virtual Int32 Cross(Vector2i^ other);
        virtual String^ ToString() override;

    public: // static
        static property Vector2i^ Zero
        {
            Vector2i^ get()
            {
                return gcnew Vector2i{ 0, 0 };
            }
        }
        static property Vector2i^ E0
        {
            Vector2i^ get()
            {
                return gcnew Vector2i{ 1, 0 };
            }
        }
        static property Vector2i^ E1
        {
            Vector2i^ get()
            {
                return gcnew Vector2i{ 0, 1 };
            }
        }

    public: // property
        property Int32 default[int]
        {
            Int32 get(int index)
            {
                try
                {
                    return (*_native)[index];
                }
                catch (std::out_of_range & exc)
                {
                    String^ msg = gcnew String(exc.what());
                    throw gcnew ArgumentOutOfRangeException(msg);
                }
            }
            void set(int index, Int32 value)
            {
                try
                {
                    (*_native)[index] = value;
                }
                catch (std::out_of_range & exc)
                {
                    String^ msg = gcnew String(exc.what());
                    throw gcnew ArgumentOutOfRangeException(msg);
                }
            }
        }
        property Double Length
        {
            Double get()
            {
                return _native->length();
            }
        }
    };
}
