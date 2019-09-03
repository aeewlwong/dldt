﻿// Copyright (c) 2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#pragma once

#include "convolution_kernel_base.h"
#include <vector>

namespace kernel_selector {

class ConvolutionKernel_bfzyx_Ref : public ConvolutionKernelBase {
public:
    ConvolutionKernel_bfzyx_Ref() : ConvolutionKernelBase("convolution_gpu_bfzyx_ref") {}
    virtual ~ConvolutionKernel_bfzyx_Ref() {}

    KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;
    ParamsKey GetSupportedKey() const override;

protected:
    std::vector<WeightsLayout> GetSupportedWeightLayouts(const convolution_params&) const override {
        return {
            WeightsLayout::oizyx,
        };
    }
};
}  // namespace kernel_selector