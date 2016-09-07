# wvsnp_image

What is it?

This is the official wvsnp image, source files, and ready to flash binaries for the WVSNP node.

License and Copyright

This is the official repository of WVSNP Project. All code, SW and Hardware contributed here is subject to NDA and agreements you have with the WVSNP Project and ASU.

Quick Start Guide:

NOTE- The following work was done on Ubuntu version 14. Everything should be do/viewable on Windows or Mac.

#To just get the binary and install and run it? Follow:

1- Grab the binary from the **_wvsnp_image/output/install directory_**.

2- Flash the SD card image binary as guided in the REAME document at: 
   [Steps for installing, running and testing the node.] (wvsnp_image/output/install/README)
   
   OR follow the guide at this step only:
   [Build succeeded! Where are my images?.] (https://docs.google.com/document/d/1i4vmpC1eP7ieGzhzHUVDzFKItHBCKrkeYED7jU4djoY/edit#heading=h.akarravwqo52) step

#How to rebuild the image from source? Follow:

1- Install the latest Yocto build tool, if not already.
   Make sure you can compile the latest board platform at:
   https://github.com/Freescale/fsl-community-bsp-platform
   
   This assumes you have used yocto at least once following our tutorial at:
   [Setting up Yocto for i.MX boards for the first time]
   (https://docs.google.com/document/d/1i4vmpC1eP7ieGzhzHUVDzFKItHBCKrkeYED7jU4djoY/edit?usp=sharing)

   And that you are able to build/compile the platform above.
   i.e. Able to complete step: "10. Start to build."
   
2- Get a copy of the repository: - Using Command Prompt (Git Bash) git clone https://github.com/adcmo/wvsnp_image.git

   Using the GitHub page While logged in to GitHub, there are URLs available in the sidebar: 
   HTTPS clone URL - Using GitHub's GUI to clone repo. Clone or download this repository.

3- Change to the **_wvsnp_image_** directory.

   At this point we assume everything has been taken care of in preparing the image
   as described in the document: [Creating a WVSNP Minimum Core Image for Wandboard (iMX6).]
   (https://docs.google.com/document/d/1Tb3JJ0qQ2kgIXkRkuj1rLBQJgZ9XEEX10lB3L8WphGo/edit?usp=sharing)
   
   So all you have to do is to jump to the [Compile Image] (https://docs.google.com/document/d/1Tb3JJ0qQ2kgIXkRkuj1rLBQJgZ9XEEX10lB3L8WphGo/edit#heading=h.fzksnu9t7jv6) step.

#How to test if the image is working as expected? Follow:

 1- do this.
    you should see?
    
 2- do this
    you should see?
  
 3- do this
    you should see?
   
 If all the above passes, you have a working WVSNP node.
   
Commiting Changes

Follow the same procedures as you would for any files. If using Git Bash, check which files have been changed with "git status" or if using GUI, see which files are showing in the change window.
