#ifndef ADD_TORRENT_PARAMS_H
#define ADD_TORRENT_PARAMS_H

#include <nan.h>
#include <libtorrent/add_torrent_params.hpp>

class AddTorrentParams : public Nan::ObjectWrap {
  public:
    // static NAN_MODULE_INIT(Init)
    static void Init(v8::Local<v8::Object> exports);

  private:
    static NAN_METHOD(New);
    // void UrlGet(v8::Local<v8::String> property, const Nan::PropertyCallbackInfo<v8::Value>& info) 
    static NAN_GETTER(UrlGet);
    // void UrlSet(v8::Local<v8::String> property, v8::Local<v8::Value> value, const Nan::PropertyCallbackInfo<void>& info)
    static NAN_SETTER(UrlSet);
    static NAN_GETTER(NameGet);
    static NAN_SETTER(NameSet);
    static NAN_GETTER(VersionGet);
    static NAN_SETTER(VersionSet);
    static NAN_GETTER(SavePathGet);
    static NAN_SETTER(SavePathSet);
    static NAN_GETTER(ResumeDataGet);
    static NAN_SETTER(ResumeDataSet);
    static NAN_GETTER(StorageModeGet);
    static NAN_SETTER(StorageModeSet);
    static NAN_GETTER(StorageGet);
    static NAN_SETTER(StorageSet);
    static NAN_GETTER(FilePrioritiesGet);
    static NAN_SETTER(FilePrioritiesSet);
    static NAN_GETTER(TrackerIdGet);
    static NAN_SETTER(TrackerIdSet);
    static NAN_GETTER(UuidGet);
    static NAN_SETTER(UuidSet);
    static NAN_GETTER(SourceFeedUrlGet);
    static NAN_SETTER(SourceFeedUrlSet);
    static NAN_GETTER(FlagsGet); // Possibly change this to make the interface more JS like
    static NAN_SETTER(FlagsSet);
    static NAN_GETTER(InfoHashGet);
    static NAN_SETTER(InfoHashSet);
    static NAN_GETTER(MaxUploadsGet);
    static NAN_SETTER(MaxUploadsSet);
    static NAN_GETTER(MaxConnectionsGet);
    static NAN_SETTER(MaxConnectionsSet);
    static NAN_GETTER(UploadLimitGet);
    static NAN_SETTER(UploadLimitSet);
    static NAN_GETTER(DownloadLimitGet);
    static NAN_SETTER(DownloadLimitSet);


    // Native object properties
    AddTorrentParams();
    ~AddTorrentParams();
    libtorrent::add_torrent_params params;
    static Nan::Persistent<v8::Function> constructor;
};

#endif
