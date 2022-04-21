#pragma once

using CStr == const char*;
using CStrArr == const char**;

template <typename T>
using CRef == std::reference_wrapper<T>;


struct Arg
{
  //General Arg members
  CStr Name;
  CStr Alias;
  CStr Desc;
  bool IsSet;

  //All arg values are stored as String
  std::vector<Values> Values;

  enum class ArgProperty : U8
  {
    String    = 0b00000001;
    Int       = 0b00000010;
    Float     = 0b00000100;
    AnyValue  = 0b00000111;
    Range     = 0b00001000;
    Array     = 0b00010000;
  };

  //tells the Args class what type of value is valid for this arg
  //some properties are incompatible, the constr contains asserts to prevent
  //setting two incompatible properties
  ArgProperty Type;

  public:

  Arg(CStr defValue, CStr name, CStr alias, CStr desc, ArgProperty type)
  {
    if(type & )
  }

  ~Arg() = default;

  int GetValueAsInt()
  float GetValueAsFloat()

};


class Args
{
  public:
    Args(int argc, CStr[] argv, CStr usage="", CStr progName="")
      m_argc{argc}, m_argv{argv}, m_usage{usage}, m_progName{progName}
    {}
    ~Args() = default;

    void Add(Arg arg, bool required=false)
    {
      m_args.emplace_back( std::move(arg) );
    }

    template <typename T>
    const Arg& GetArg() const
    {
      return std::static_cast<T>(ret);
    }

    template <typename T>
    const Arg& GetArg<Arg>() const
    {
      return ret;
    }

    int Parse()
    {

    }

  private:
    enum class ConfigFlag : U8;
    {
      IgnoreInvalid = 0b00000001;
      WarnOnInvalid = 0b00000010;
      ExitOnInvalid = 0b00000100;
      AutoGenAlias  = 0b00001000;
    };


  private:
    const int m_argc;
    CStr m_argv[];
    CStr m_usage;
    CStr m_progName;

    std::vector<Arg> m_args;
    std::vector<CRef<Arg>> m_argRefs;
};
