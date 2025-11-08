# Lyric Editor Beta

**By:** TomRiddle901

> This program is for personal use only. Any unauthorized use is the user's responsibility.

---

## Description

Lyric Editor is a small song lyrics editor designed for personal use on Linux systems. It allows you to load, edit, and save lyrics, manage simple versions, and display lyrics in a view suitable for practice or testing.

This project requires **Qt5** libraries for the GUI.

> **Note:** No further updates are planned for this application, as a new HTML5 app is being developed to replace it. The program is only in Italian sorry :|

---

## Main Features

* Open, edit, and save text files (*.txt, *.lrc)
* Change background color and text font
* Load music to sync with lyrics

---

## Requirements

### To run the application (pre-compiled executable)

* **Linux Kernel** (tested on Debian-based distributions)
* **Qt5** libraries and runtime

**Instructions:**

```bash
chmod +x Lyric_Editor_Beta
./Lyric_Editor_Beta
```

**If Qt5 is not installed:**

```bash
sudo apt install qtbase5-dev qt5-qmake
```

### If the executable doesn't work

You can download the source code and recompile it.

**Requirements for compilation:**

* Qt5 development libraries
* Build tools: `g++`, `qmake` or `cmake`, `make`

**Compile with g++:**

```bash
cd /project/path
# compile the source
g++ LrcEditor.cpp -o LyricEditor $(pkg-config --cflags --libs Qt5Widgets)
# run the app
./LyricEditor
```

---

## Use

1. Run the app.
2. Load audio files (*.wav, *.mp3, ...).
3. Click Play and listen.
4. Before the beginning of a stanza, click `Insert text`.
5. Write or copy/paste lyrics.
6. Click `OK`.
7. When finished, click `Save LRC`.

**To edit an existing *.lrc file:**

1. Click `Load existing *.lrc`.
2. Edit the text.
3. Save changes.

### Preferences

* Set font and text size.
* Adjust background color for easier reading.

---

## Troubleshooting

**Qt5 not found:**

* Make sure `qt5-default` or the Qt5 development packages are installed.
* On Debian/Ubuntu: `sudo apt install qtbase5-dev qt5-qmake`

**Permission denied when executing:**

* Make the binary executable: `chmod +x LyricEditor`

**Crash on startup:**

* Run from the terminal to see error messages.
* Check for missing libraries: `ldd ./LyricEditor`

**Strange characters or encoding issues:**

* Ensure your file is encoded in UTF-8.

If the problem persists, copy the terminal output and create an issue.

---

## Changelog (v1.0)

* First public release. Basic functionality: open, edit, save files.

---

*Note:* This software is provided for personal use only. The user is responsible for legal and authorized use.

