#ifndef MACROS_H
#define MACROS_H

// Some useful macros are dumped here

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
// <Copied from Google C++ style guide>
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

// A macro to disallow the copy constructor only
// This should be used in the private: declarations for a class
// <Inspired from Google C++ style guide>
#define DISALLOW_COPY(TypeName) \
  TypeName(const TypeName&);

// Some customized Assert macro
#if defined(DEBUG) || defined(_DEBUG)
#define ASSERT(x) \
    if (! (x)) \
    { \
    cout << "ERROR! Assert " << #x << " failed\n"; \
    cout << " on line " << __LINE__  << "\n"; \
    cout << " in file " << __FILE__ << "\n";  \
    }
#else
#define ASSERT(x)
#endif

#endif // MACROS_H
