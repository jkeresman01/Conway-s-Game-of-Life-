#pragma once

#include <random>

#include "Cell.h"

namespace gol
{

class Random
{
  public:
    static void Init() { s_randomEngine.seed(std::random_device()()); }

    static uint32_t generate(uint32_t max) { return s_distribution(s_randomEngine) % (max + 1); }

    static State cellState() { return Random::generate(100) < 25 ? State::ALIVE : State::DEAD; }

  private:
    inline static std::mt19937 s_randomEngine;
    inline static std::uniform_int_distribution<std::mt19937::result_type> s_distribution;
};

} // namespace gol
