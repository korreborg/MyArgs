#define MYARGS_GLOBAL_ARGS
#define MYARGS_AUTOGEN_HELP
#define MYARGS_AUTOGEN_USAGE
#include <MyArgs/Args.hpp>

int main(int argc, char** argv)
{

  //-verbose, -verbose=false, -verbose false, -verbose 0
  Args::Flag verbose{false, "verbose", "prints additional info"};
  
  //-secHeader 5, -secHeader=5, -secHeader=.bss, -secHeader .bss
  Args::Arg<Alphanum> secHeader{0, "secHeader", "prints section header of specific section"};

  Args::Arg<int> secHeader{0, "secHeader", "prints section header of specific section"};

  secHeader.Set(), secHeader.ValueAsInt();

  //-secHeaders (all), -secHeaders=5, -secHeaders 5, -secHeaders -n=5
  Args::ItrArg secHeaders{0, "secHeaders", "prints seciton headers"};

  Args::Arg mapSection{0, "mapSection", "shows which segment the specified section resides in"};
  Args::Arg mapSegment{0, "mapSegment", "shows which sections reside in the specified segment"};

  Args::ItrArg mapSections{0, "mapSetions", "shows which sections overlap segments"};

  std::vector<const char*> input;
  Args::Args(input, Args::Config::IgnoreInvalidFlags, 
             argc, argv, "usage", "progName");

  for(const char* fileStr : inputStrs)
  {
    Elf elf{fileStr};
    //...
  }

  //

  Args::Args args{argc, argv, "usage"};

  //--input=/home/elf.a,/home/elf2.a,/home/elf3.a

  //--secHeaders -n 5

  Args::Arg verbose{false, "verbose", ""};
  args.Add(verbose);

  args.AddArg<Flag>("verbose", false, );
  args.AddArg<Alphanum>("secHeader");

  args.Parse(input, Args::Config::IgnoreInvalidFlags);

  args.IsSet("secHeader");
  args.GetValue<int>("secHeader");

  return 0;
}

