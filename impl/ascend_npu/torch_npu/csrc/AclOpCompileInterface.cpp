// Copyright (c) 2020 Huawei Technologies Co., Ltd
// All rights reserved.
//
// Licensed under the BSD 3-Clause License  (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <c10/util/Exception.h>
#include <c10/util/Optional.h>

#include "acl/acl_base.h"
#include "acl/acl_op_compiler.h"

namespace at_npu {
namespace native {
#define GET_FUNC(funcName) funcName

aclError AclSetCompileopt(aclCompileOpt opt, const char *value) {
    typedef aclError (*aclSetCompileoptFunc)(aclCompileOpt opt, const char *value);
    static aclSetCompileoptFunc func = nullptr;
    if (func == nullptr) {
        func = (aclSetCompileoptFunc)GET_FUNC(aclSetCompileopt);
    }
    TORCH_CHECK(func, "Failed to find function ", "aclSetCompileopt");
    auto ret = func(opt, value);
    return ret;
}

c10::optional<size_t> AclGetCompileoptSize(aclCompileOpt opt) {
    typedef aclError (*aclGetCompileoptSizeFunc)(aclCompileOpt opt);
    static aclGetCompileoptSizeFunc func = nullptr;
    if (func == nullptr) {
        func = (aclGetCompileoptSizeFunc)GET_FUNC(aclGetCompileoptSize);
    }
    if (func == nullptr) {
        return c10::nullopt;
    } else {
        return func(opt);
    }
}

aclError AclGetCompileopt(aclCompileOpt opt, char *value, size_t length) {
    typedef aclError (*aclGetCompileoptFunc)(aclCompileOpt opt, char *value, size_t length);
    static aclGetCompileoptFunc func = nullptr;
    if (func == nullptr) {
        func = (aclGetCompileoptFunc)GET_FUNC(aclGetCompileopt);
    }
    if (func == nullptr) {
        return ACL_ERROR_GE_FAILURE;
    } else {
        return func(opt, value, length);
    }
}

aclError AclGenGraphAndDumpForOp(const char *opType, int numInputs, const aclTensorDesc *const inputDesc[], const aclDataBuffer *const inputs[], int numOutputs,
                                 const aclTensorDesc *const outputDesc[], aclDataBuffer *const outputs[], const aclopAttr *attr, aclopEngineType engineType,
                                 const char *graphDumpPath, aclGraphDumpOption *graphdumpOpt) {
    typedef aclError (*AclGenGraphAndDumpForOpFunc)(const char *,
                                                    int,
                                                    const aclTensorDesc *const[],
                                                    const aclDataBuffer *const[],
                                                    int,
                                                    const aclTensorDesc *const[],
                                                    aclDataBuffer *const[],
                                                    const aclopAttr *,
                                                    aclopEngineType,
                                                    const char *,
                                                    aclGraphDumpOption *);
    static AclGenGraphAndDumpForOpFunc func = nullptr;
    if (func == nullptr) {
        // func = (AclGenGraphAndDumpForOpFunc)GET_FUNC(aclGenGraphAndDumpForOp);
    }
    TORCH_CHECK(func, "Failed to find function ", "aclGenGraphAndDumpForOp");
    auto ret = func(opType, numInputs, inputDesc, inputs, numOutputs, outputDesc, outputs, attr, engineType, graphDumpPath, graphdumpOpt);
    return ret;
}

aclGraphDumpOption *AclCreateGraphDumpOpt() {
    typedef aclGraphDumpOption *(*AclCreateGraphDumpOptFunc)();
    static AclCreateGraphDumpOptFunc func = nullptr;
    if (func == nullptr) {
        func = (AclCreateGraphDumpOptFunc)GET_FUNC(aclCreateGraphDumpOpt);
    }
    TORCH_CHECK(func, "Failed to find function ", "aclCreateGraphDumpOpt");
    return func();
}

aclError AclDestroyGraphDumpOpt(aclGraphDumpOption *aclGraphDumpOpt) {
    typedef aclError (*AclDestroyGraphDumpOptFunc)(aclGraphDumpOption *);
    static AclDestroyGraphDumpOptFunc func = nullptr;
    if (func == nullptr) {
        // func = (AclDestroyGraphDumpOptFunc)GET_FUNC(aclDestroyGraphDumpOpt);
    }
    TORCH_CHECK(func, "Failed to find function ", "aclDestroyGraphDumpOpt");
    return func(aclGraphDumpOpt);
}

aclError AclopCompileAndExecuteV2(const char *opType, int numInputs, aclTensorDesc *inputDesc[], aclDataBuffer *inputs[], int numOutputs,
                                  aclTensorDesc *outputDesc[], aclDataBuffer *outputs[], aclopAttr *attr, aclopEngineType engineType,
                                  aclopCompileType compileFlag, const char *opPath, aclrtStream stream) {
    typedef aclError (*AclopCompileAndExecuteV2Func)(const char *,
                                                     int,
                                                     aclTensorDesc *[],
                                                     aclDataBuffer *[],
                                                     int,
                                                     aclTensorDesc *[],
                                                     aclDataBuffer *[],
                                                     aclopAttr *,
                                                     aclopEngineType,
                                                     aclopCompileType,
                                                     const char *,
                                                     aclrtStream);
    static AclopCompileAndExecuteV2Func func = nullptr;
    if (func == nullptr) {
        func = (AclopCompileAndExecuteV2Func)GET_FUNC(aclopCompileAndExecuteV2);
    }
    TORCH_CHECK(func, "Failed to find function ", "aclopCompileAndExecuteV2");
    auto ret = func(opType, numInputs, inputDesc, inputs, numOutputs, outputDesc, outputs, attr, engineType, compileFlag, opPath, stream);
    return ret;
}

aclError AclrtCtxSetSysParamOpt(aclSysParamOpt opt, int64_t value) {
    typedef aclError (*AclrtCtxSetSysParamOptFunc)(aclSysParamOpt opt, int64_t value);
    static AclrtCtxSetSysParamOptFunc func = nullptr;
    if (func == nullptr) {
        // func = (AclrtCtxSetSysParamOptFunc)GET_FUNC(aclrtCtxSetSysParamOpt);
    }
    if (func == nullptr) {
        TORCH_WARN("Failed to find this aclrtCtxSetSysParamOpt function!");
        return ACL_ERROR_NONE;
    }
    auto ret = func(opt, value);
    return ret;
}

}  // namespace native
}  // namespace at_npu
