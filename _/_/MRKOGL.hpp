#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <source_location>
#include <fstream>
#include <array>
#include <algorithm>
#include <limits>
#include <filesystem>
#include <numbers>

#pragma warning(push)
#pragma warning(disable : 4267 6385 26495 26819 33010)
#include "..\\SLSDL\\sdl.h"
#include "..\\SLSDL\\sdl_opengl.h"
#include "..\\SLSDLLI\\sdl_image.h"
#include "..\\SLSDLLM\\sdl_mixer.h"
#include "..\\SLSDLLT\\sdl_ttf.h"
#include "..\\AOL\\scene.h"
#include "..\\AOL\\cimport.h"
#include "..\\CGALOSP\\Simple_cartesian.h"
#pragma warning(pop)

#include <gl\\glu.h>