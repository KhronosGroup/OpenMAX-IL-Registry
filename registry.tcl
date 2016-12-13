# registry.tcl
#
# This is a simple human-readable database defining the OpenMAX IL
# extension registry. For each extension, it includes an extension
# number, flags if the extension is public, and includes a path to
# the extension specification.

# Extra directories to pick up IL extension specs outside the registry tree
set ilext ../../../OpenMAX-IL/trunk/OpenMAX_IL_1/doc/extensions
lappend extraDirs $ilext

extdocument "OpenMAX IL Deferred Commit" {
    number      1
    flags       public
    filename    "../../../OpenMAX-IL/trunk/OpenMAX_IL_1/doc/extensions/OpenMAX_IL_1_1_2_Extension Deferred Commit.pdf"
    vendor      KHR
}
extdocument "OpenMAX IL Extended Callback Events" {
    number      2
    flags       public
    filename    "../../../OpenMAX-IL/trunk/OpenMAX_IL_1/doc/extensions/OpenMAX_IL_1_1_2_Extension Extended Callback Events.pdf"
    vendor      KHR
}
extdocument "OpenMAX IL NAL Unit Packaging" {
    number      3
    flags       public
    filename    "../../../OpenMAX-IL/trunk/OpenMAX_IL_1/doc/extensions/OpenMAX_IL_1_1_2_Extension NAL Unit Packaging.pdf"
    vendor      KHR
}
extdocument "OpenMAX IL VP8 and WebP Codec" {
    number      4
    flags       public
    filename    "../../../OpenMAX-IL/trunk/OpenMAX_IL_1/doc/extensions/OpenMAX_IL_1_1_2_Extension VP8 WebP.pdf"
    vendor      KHR
}
# Next free extension number: 5
