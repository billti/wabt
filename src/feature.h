/*
 * Copyright 2017 WebAssembly Community Group participants
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WABT_FEATURE_H_
#define WABT_FEATURE_H_

#include "common.h"

namespace wabt {

class OptionParser;

class Features {
 public:
  void AddOptions(OptionParser*);

#define WABT_FEATURE(variable, flag, help) \
  bool variable##_enabled() const { return variable##_enabled_; }
#include "feature.def"
#undef WABT_FEATURE

 private:
#define WABT_FEATURE(variable, flag, help) \
  bool variable##_enabled_ = false;
#include "feature.def"
#undef WABT_FEATURE
};

}  // namespace wabt

#endif // WABT_FEATURE_H_
