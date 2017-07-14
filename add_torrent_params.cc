#include "add_torrent_params.h"

Nan::Persistent<v8::Function> AddTorrentParams::constructor;

// Constructor
AddTorrentParams::AddTorrentParams() {}
AddTorrentParams::~AddTorrentParams() {}


// void New(const Nan::FunctionCallbackInfo<v8::Value>& info)
NAN_METHOD(AddTorrentParams::New) {
  if(info.IsConstructCall()){
    AddTorrentParams* torrentParams = new AddTorrentParams();
    torrentParams->Wrap(info.This()); // This binds the c++ object to the js object
    info.GetReturnValue().Set(info.This());
  }else{
    //const int argc = 0;
    //v8::Local<v8::Value> argv[argc] = {};
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(Nan::GetCurrentContext()).ToLocalChecked());
  }
}

// void UrlGet(v8::Local<v8::String> property, const Nan::PropertyCallbackInfo<v8::Value>& info) 
NAN_GETTER(AddTorrentParams::UrlGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto url = Nan::New(params->params.url).ToLocalChecked();
  info.GetReturnValue().Set(url);
}

// void UrlSet(v8::Local<v8::String> property, v8::Local<v8::Value> value, const Nan::PropertyCallbackInfo<void>& info)
NAN_SETTER(AddTorrentParams::UrlSet) {
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  v8::Local<v8::String> url = Nan::To<v8::String>(value).ToLocalChecked();
  params->params.url = *Nan::Utf8String(url);
}
NAN_GETTER(AddTorrentParams::NameGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto name = Nan::New(params->params.name).ToLocalChecked();
  info.GetReturnValue().Set(name);
}
NAN_SETTER(AddTorrentParams::NameSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  v8::Local<v8::String> name = Nan::To<v8::String>(value).ToLocalChecked();
  params->params.name = *Nan::Utf8String(name);
}

NAN_GETTER(AddTorrentParams::VersionGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto version = Nan::New(params->params.version);
  info.GetReturnValue().Set(version);
}
NAN_SETTER(AddTorrentParams::VersionSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto version = value->NumberValue(Nan::GetCurrentContext()).FromMaybe(0);
  params->params.version = version;
}
NAN_GETTER(AddTorrentParams::SavePathGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto savePath = Nan::New(params->params.save_path).ToLocalChecked();
  info.GetReturnValue().Set(savePath);
}
NAN_SETTER(AddTorrentParams::SavePathSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  v8::Local<v8::String> savePath = Nan::To<v8::String>(value).ToLocalChecked();
  params->params.save_path = *Nan::Utf8String(savePath);
}
NAN_GETTER(AddTorrentParams::ResumeDataGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  std::vector<char> libtorrentResumeData = params->params.resume_data;
  // We just use strings, rather than vectors of chars, so we should convert from 
  // vector of char to a string
  std::string stringResumeData(libtorrentResumeData.begin(), libtorrentResumeData.end());
  auto resumeData = Nan::New(stringResumeData).ToLocalChecked();
  info.GetReturnValue().Set(resumeData);
}
NAN_SETTER(AddTorrentParams::ResumeDataSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  v8::Local<v8::String> resumeDataInput = Nan::To<v8::String>(value).ToLocalChecked();
  const std::string resumeDataString = *Nan::Utf8String(resumeDataInput);
  const std::vector<char> saveData(resumeDataString.begin(), resumeDataString.end());
  params->params.resume_data = saveData;
}
NAN_GETTER(AddTorrentParams::StorageModeGet){}
NAN_SETTER(AddTorrentParams::StorageModeSet){}
NAN_GETTER(AddTorrentParams::StorageGet){}
NAN_SETTER(AddTorrentParams::StorageSet){}
NAN_GETTER(AddTorrentParams::UserDataGet){}
NAN_SETTER(AddTorrentParams::UserDataSet){}
NAN_GETTER(AddTorrentParams::FilePrioritiesGet){}
NAN_SETTER(AddTorrentParams::FilePrioritiesSet){}
NAN_GETTER(AddTorrentParams::TrackerIdGet){}
NAN_SETTER(AddTorrentParams::TrackerIdSet){}
NAN_GETTER(AddTorrentParams::UuidGet){}
NAN_SETTER(AddTorrentParams::UuidSet){}
NAN_GETTER(AddTorrentParams::SourceFeedUrlGet){}
NAN_SETTER(AddTorrentParams::SourceFeedUrlSet){}
NAN_GETTER(AddTorrentParams::FlagsGet){}
NAN_SETTER(AddTorrentParams::FlagsSet){}
NAN_GETTER(AddTorrentParams::InfoHashGet){}
NAN_SETTER(AddTorrentParams::InfoHashSet){}
NAN_GETTER(AddTorrentParams::MaxUploadsGet){}
NAN_SETTER(AddTorrentParams::MaxUploadsSet){}
NAN_GETTER(AddTorrentParams::MaxConnectionsGet){}
NAN_SETTER(AddTorrentParams::MaxConnectionsSet){}
NAN_GETTER(AddTorrentParams::UploadLimitGet){}
NAN_SETTER(AddTorrentParams::UploadLimitSet){}
NAN_GETTER(AddTorrentParams::DownloadLimitGet){}


void AddTorrentParams::Init(v8::Local<v8::Object> exports){
  Nan::HandleScope scope;

  //Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("AddTorrentParams").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  v8::Local<v8::String> accessorName = Nan::New("url").ToLocalChecked();
  Nan::SetAccessor(tpl->InstanceTemplate(), accessorName, UrlGet, UrlSet);
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("name").ToLocalChecked(), NameGet, NameSet);
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), VersionGet, VersionSet);
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("savePath").ToLocalChecked(), SavePathGet, SavePathSet);
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("resumeData").ToLocalChecked(), ResumeDataGet, ResumeDataSet);
 
  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("AddTorrentParams").ToLocalChecked(), tpl->GetFunction());
}
