#pragma once

class digitLink
{
    public:
      char elm;
      const int *arr;

      static int membersNb;

    digitLink(char e, const int* a)
    {
      elm = e;
      arr = a;  
      membersNb++;
    }
};

int digitLink::membersNb;
