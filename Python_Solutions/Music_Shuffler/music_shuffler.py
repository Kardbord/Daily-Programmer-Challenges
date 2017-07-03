# think about how to design this system:
# possible design:
# A Track class with Artist and Album members
# A Playlist class with an array of Tracks, and a shuffle function
# Other Stuff:
# Take inputs from a file if possible to build a Track library/Playlist


class Track(object):
    def __init__(self, name, artist, album, pk):
        self.name = name
        self.artist = artist
        self.album = album
        self.pk = pk


class Playlist(object):
    def __init__(self):
        self.tracks = []

    def add_track(self, new_track):
        if not any(track.pk == new_track.pk for track in self.tracks):
            self.tracks.append(new_track)

    def list(self):
        for track in self.tracks:
            print track.name

    # def shuffle(self):
            # TODO: implement this
