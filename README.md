HOW TO BUILD PACKAGE
====================

Change path to inside root directory of git repo.

`sudo dpkg-deb --build nova`

Will generate nova.deb

HOW TO INSTALL PACKAGE
======================

`sudo dpkg -i nova.deb`

Enter password if necessary, then novac should be available to use.

You can check novac by running the command `novac` and seeing if it outputs the version.
