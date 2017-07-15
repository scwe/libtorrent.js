const libtorrent = require('bindings')('torrent')

console.log('libtorrent is: ', libtorrent)
const params = new libtorrent.AddTorrentParams()
console.log("Params are: ", params)

params.url = "something something"
console.log('Params are: ', params.url)

params.filePriorities = [1,2,3,4]
console.log('Now: ', params.filePriorities)

