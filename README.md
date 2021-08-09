# OpenMAX-IL-Registry

The OpenMAX-IL-Registry repository contains the OpenMAX IL API and Extension
Registry, including specifications.

It is also used as a backing store for the web view of the registry at
https://www.khronos.org/registry/omxil/ ; commits to the main branch of
this repository will be reflected there.

**NOTE**: as of 2021-07-21, the default branch of this repository has
been renamed from 'master' to 'main'.

In the past, the OpenMAX IL registry was maintained in a public Subversion
repository. The history in that repository has not been imported to github,
but it is still available at
https://cvs.khronos.org/svn/repos/registry/trunk/public/omxil/ .

Interesting files in this repository include:

* index.php - toplevel index page for the web view. This relies on PHP
  include files found elsewhere on www.khronos.org and so is not very useful
  in isolation.
* api/ - OpenMAX IL header files
* extensions/ - OpenMAX IL extension specifications, grouped into
  vendor-specific subdirectories.
* specs/ - OpenMAX IL specification documents.


## Adding Extension Specifications

Extension specification documents can be added by proposing a pull request
adding the specification PDF (and related source markup, if
available) files under extensions/<vendor>/ . You must also:

* Allocate an extension number in registry.tcl (follow the existing
  extension examples, search for "Next free extension number", and use the
  lowest available extension number.
* Include that extension number in the extension specification document.
* Add a link from the extensions section of index.php to the extension
  document, using the specified extension number, so it shows up in the web
  view.

