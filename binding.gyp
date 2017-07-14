{
  "targets": [
    {
      "target_name": "libtorrent",
      "include_dirs" : [
            "<!(node -e \"require('nan')\")"
      ],
      "sources": [ 
        "main.cc",
        "add_torrent_params.cc"
      ],
      "libraries": [
        "/usr/local/lib/libtorrent-rasterbar.a",
        "/usr/local/lib/libboost_system.a",
        "/usr/local/lib/libssl.a",
        "/usr/local/lib/libcrypto.a"
      ],
      "something_else": [
        "-pthread", 
        "-ltorrent-rasterbar", 
        "-lboost_system", 
        "-lssl", 
        "-lcrypto"
      ]
    }
  ]
}
