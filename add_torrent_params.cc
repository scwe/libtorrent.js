#include "add_torrent_params.h"
#include <libtorrent/storage_defs.hpp>

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
NAN_GETTER(AddTorrentParams::StorageModeGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto storage_mode = Nan::New(params->params.storage_mode);
  info.GetReturnValue().Set(storage_mode);
}
NAN_SETTER(AddTorrentParams::StorageModeSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  int storage_mode = (int)(value->NumberValue(Nan::GetCurrentContext()).FromMaybe(0));
  libtorrent::storage_mode_t torrentStorage = static_cast<libtorrent::storage_mode_t>(storage_mode);
  params->params.storage_mode = torrentStorage;
}
NAN_GETTER(AddTorrentParams::StorageGet){}
NAN_SETTER(AddTorrentParams::StorageSet){}
NAN_GETTER(AddTorrentParams::FilePrioritiesGet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  auto file_priorities = params->params.file_priorities;
  v8::Local<v8::Array> v8Priorities = Nan::New<v8::Array>();

  for(unsigned int i = 0; i < file_priorities.size(); i++){
    v8Priorities->Set(i, Nan::New(file_priorities[i]));
  }

  info.GetReturnValue().Set(v8Priorities);
}
NAN_SETTER(AddTorrentParams::FilePrioritiesSet){
  auto params = Nan::ObjectWrap::Unwrap<AddTorrentParams>(info.Holder());
  v8::Local<v8::Object> filePriorityData = Nan::To<v8::Object>(value).ToLocalChecked();
  unsigned int length = filePriorityData->Get(Nan::New("length").ToLocalChecked())->ToObject()->Uint32Value();
  std::vector<unsigned char> file_priorities(length);

  for(unsigned int i = 0; i < length; i++){
    file_priorities[i] = (unsigned char)filePriorityData->Get(Nan::New(i))->IntegerValue();
  }
  params->params.file_priorities = file_priorities;
}
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
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("storageMode").ToLocalChecked(), StorageModeGet, StorageModeSet);
  Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("filePriorities").ToLocalChecked(), FilePrioritiesGet, FilePrioritiesSet);
 
  v8::Local<v8::Object> flagsEnum = Nan::New<v8::Object>();
  flagsEnum->Set(Nan::New("flag_seed_mode").ToLocalChecked(), Nan::New(1));
  flagsEnum->Set(Nan::New("flag_override_resume_data").ToLocalChecked(), Nan::New(2));
  flagsEnum->Set(Nan::New("flag_upload_mode").ToLocalChecked(), Nan::New(4));
  flagsEnum->Set(Nan::New("flag_share_mode").ToLocalChecked(), Nan::New(8));
  flagsEnum->Set(Nan::New("flag_apply_ip_filter").ToLocalChecked(), Nan::New(16));
  flagsEnum->Set(Nan::New("flag_paused").ToLocalChecked(), Nan::New(32));
  flagsEnum->Set(Nan::New("flag_auto_managed").ToLocalChecked(), Nan::New(64));
  flagsEnum->Set(Nan::New("flag_duplicate_is_error").ToLocalChecked(), Nan::New(128));
  flagsEnum->Set(Nan::New("flag_merge_resume_trackers").ToLocalChecked(), Nan::New(256));
  flagsEnum->Set(Nan::New("flag_update_subscribe").ToLocalChecked(), Nan::New(512));
  flagsEnum->Set(Nan::New("flag_super_seeding").ToLocalChecked(), Nan::New(1024));
  flagsEnum->Set(Nan::New("flag_sequential_download").ToLocalChecked(), Nan::New(2048));
  flagsEnum->Set(Nan::New("flag_use_resume_save_path").ToLocalChecked(), Nan::New(4096));
  flagsEnum->Set(Nan::New("flag_pinned").ToLocalChecked(), Nan::New(8192));
  flagsEnum->Set(Nan::New("flag_stop_when_ready").ToLocalChecked(), Nan::New(16284));
  flagsEnum->Set(Nan::New("flag_merge_resume_http_seeds").ToLocalChecked(), Nan::New(32768));

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("AddTorrentParams").ToLocalChecked(), tpl->GetFunction());
  exports->Set(Nan::New("AddTorrentParamsFlags").ToLocalChecked(), flagsEnum);
}
