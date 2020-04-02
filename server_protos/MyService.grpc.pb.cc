// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: MyService.proto

#include "MyService.pb.h"
#include "MyService.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace server {

static const char* MyService_method_names[] = {
  "/server.MyService/do_something",
};

std::unique_ptr< MyService::Stub> MyService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MyService::Stub> stub(new MyService::Stub(channel));
  return stub;
}

MyService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_do_something_(MyService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MyService::Stub::do_something(::grpc::ClientContext* context, const ::server::Request& request, ::server::Response* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_do_something_, context, request, response);
}

void MyService::Stub::experimental_async::do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_do_something_, context, request, response, std::move(f));
}

void MyService::Stub::experimental_async::do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_do_something_, context, request, response, std::move(f));
}

void MyService::Stub::experimental_async::do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_do_something_, context, request, response, reactor);
}

void MyService::Stub::experimental_async::do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_do_something_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::server::Response>* MyService::Stub::Asyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::server::Response>::Create(channel_.get(), cq, rpcmethod_do_something_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::server::Response>* MyService::Stub::PrepareAsyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::server::Response>::Create(channel_.get(), cq, rpcmethod_do_something_, context, request, false);
}

MyService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MyService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MyService::Service, ::server::Request, ::server::Response>(
          [](MyService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::server::Request* req,
             ::server::Response* resp) {
               return service->do_something(ctx, req, resp);
             }, this)));
}

MyService::Service::~Service() {
}

::grpc::Status MyService::Service::do_something(::grpc::ServerContext* context, const ::server::Request* request, ::server::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace server

