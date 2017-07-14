const libtorrent = require('bindings')('torrent')

console.log('libtorrent is: ', libtorrent)
const params = new libtorrent.AddTorrentParams()
console.log("Params are: ", params)

params.url = "something something"
console.log('Params are: ', params.url)

