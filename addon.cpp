#include <node.h>

namespace calculate
{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Number;
    using v8::Value;


    void Method(const FunctionCallbackInfo<Value>& args)
    {
        Isolate* isolate = args.GetIsolate();
        double x = 100.12357768;
        double y = 200.12319223;
        for(int i = 0; i < 1000000; i++)
        {
            x += y;
        }
        auto total = Number::New(isolate, x);
        args.GetReturnValue().Set(total);
    }
    void Initalize(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "calc", Method);
    }
    NODE_MODULE(NODE_GYP_MODULE_NAME, Initalize); 
}