#include <nan.h>
#include <libtorrent/session.hpp>
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_handle.hpp>
#include "add_torrent_params.h"

/*
void CreateObject(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Local<Object> obj = Nan::New<Object>();
  obj->Set(Nan::New("msg").ToLocalChecked(), info[0]->ToString());

  info.GetReturnValue().Set(obj);
}

void CreateTorrentParams(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Local<Object> obj = Nan::New<Object>();
  
  MaybeLocal<v8::Object> args = Nan::To<v8::Object>(info[0]);

  Local<v8::Value> url = args.ToLocalChecked()->Get(Nan::New("url").ToLocalChecked());
  
  //add_torrent_params_wrap params_wrap;

  obj->Set(Nan::New("url").ToLocalChecked(), url);
  info.GetReturnValue().Set(obj);
}*/

void Initialize(v8::Local<v8::Object> exports) {  
  //module->Set(Nan::New("exports").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(CreateObject)->GetFunction());
  /*v8::Local<v8::Object> libtorrentObj = Nan::New<v8::Object>();

  libtorrentObj->Set(Nan::New("add_torrent_params").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(CreateTorrentParams)->GetFunction());

  module->Set(Nan::New("exports").ToLocalChecked(), libtorrentObj);*/

  AddTorrentParams::Init(exports);
}

NODE_MODULE(libtorrent, Initialize)  
