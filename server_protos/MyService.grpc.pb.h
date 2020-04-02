// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: MyService.proto
#ifndef GRPC_MyService_2eproto__INCLUDED
#define GRPC_MyService_2eproto__INCLUDED

#include "MyService.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace server {

class MyService final {
 public:
  static constexpr char const* service_full_name() {
    return "server.MyService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status do_something(::grpc::ClientContext* context, const ::server::Request& request, ::server::Response* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>> Asyncdo_something(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>>(Asyncdo_somethingRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>> PrepareAsyncdo_something(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>>(PrepareAsyncdo_somethingRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, std::function<void(::grpc::Status)>) = 0;
      virtual void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>* Asyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::server::Response>* PrepareAsyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status do_something(::grpc::ClientContext* context, const ::server::Request& request, ::server::Response* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::server::Response>> Asyncdo_something(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::server::Response>>(Asyncdo_somethingRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::server::Response>> PrepareAsyncdo_something(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::server::Response>>(PrepareAsyncdo_somethingRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, std::function<void(::grpc::Status)>) override;
      void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void do_something(::grpc::ClientContext* context, const ::server::Request* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void do_something(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::server::Response* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::server::Response>* Asyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::server::Response>* PrepareAsyncdo_somethingRaw(::grpc::ClientContext* context, const ::server::Request& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_do_something_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status do_something(::grpc::ServerContext* context, const ::server::Request* request, ::server::Response* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_do_something() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestdo_something(::grpc::ServerContext* context, ::server::Request* request, ::grpc::ServerAsyncResponseWriter< ::server::Response>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_do_something<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_do_something() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::server::Request, ::server::Response>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::server::Request* request, ::server::Response* response) { return this->do_something(context, request, response); }));}
    void SetMessageAllocatorFor_do_something(
        ::grpc::experimental::MessageAllocator< ::server::Request, ::server::Response>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::server::Request, ::server::Response>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* do_something(
      ::grpc::CallbackServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* do_something(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_do_something<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_do_something<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_do_something() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_do_something() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestdo_something(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_do_something() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->do_something(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* do_something(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* do_something(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_do_something : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_do_something() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::server::Request, ::server::Response>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::server::Request, ::server::Response>* streamer) {
                       return this->Streameddo_something(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_do_something() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status do_something(::grpc::ServerContext* /*context*/, const ::server::Request* /*request*/, ::server::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status Streameddo_something(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::server::Request,::server::Response>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_do_something<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_do_something<Service > StreamedService;
};

}  // namespace server


#endif  // GRPC_MyService_2eproto__INCLUDED
