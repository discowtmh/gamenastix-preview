// This file is a part of opengl-stickyman project.
// Copyright 2018 Aleksander Gajewski <adiog@brainfuck.pl>.

#pragma once

#include <unordered_map>

#include <glm/glm.hpp>
#include <bio/Segment.h>
#include <bio/Sequence.h>


namespace model {
struct Layout
{
#ifdef _WIN32
    std::unordered_map<bio::Segment, glm::vec3, EnumClassHash> segmentLayout;
    std::unordered_map<bio::Sequence, glm::vec3, EnumClassHash> sequenceLayout;
#else
    std::unordered_map<bio::Segment, glm::vec3> segmentLayout;
    std::unordered_map<bio::Sequence, glm::vec3> sequenceLayout;
#endif
};
}
