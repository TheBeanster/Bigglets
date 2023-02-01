#pragma once

#include <iostream>



#define clog(l) std::clog << __FUNCSIG__ << l << '\n';
#define cerr(l) std::cerr << "ERROR! in " << __func__ << l << '\n';
