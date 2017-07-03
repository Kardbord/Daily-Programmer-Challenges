# think about how to design this system:
# possible design:
# A Track class with Artist and Album members
# A Playlist class with an array of Tracks, and a shuffle function
# Other Stuff:
# Take inputs from a file if possible to build a Track library/Playlist


class Track(object):
    def __init__(self, artist, album, pk):
        self.artist = artist
        self.album = album
