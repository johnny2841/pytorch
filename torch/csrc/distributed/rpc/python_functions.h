#pragma once


#include <torch/csrc/distributed/rpc/FutureMessage.h>
#include <torch/csrc/distributed/rpc/Message.h>
#include <torch/csrc/distributed/rpc/RpcAgent.h>
#include <torch/csrc/distributed/rpc/ScriptCall.h>
#include <torch/csrc/distributed/rpc/ScriptRet.h>
#include <torch/csrc/jit/pybind_utils.h>
#include <torch/csrc/utils/pybind.h>
#include <torch/csrc/distributed/rpc/PythonRpcHandler.h>


namespace torch {
namespace distributed {
namespace rpc {

py::object to_py_obj(const Message& message);

FutureMessage::Callback wrap_callback(
    FutureMessage& fut, const std::function<void(FutureMessage&)> py_cb);

std::shared_ptr<FutureMessage> py_rpc_builtin(
    RpcAgent& agent,
    const std::string& dstName,
    const std::string& opName,
    const py::args& args,
    const py::kwargs& kwargs);

std::shared_ptr<FutureMessage>  py_rpc_python_udf(
    RpcAgent& agent,
    const std::string& dstName,
    const std::string& pickledPythonUDF);

}
}
}
