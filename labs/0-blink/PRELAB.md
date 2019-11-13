## Lab 0 - Blink - Prep Worksheet
### Background Summary

As mentioned in the README, this lab will focus on getting you comfortable with the physical R/Pi as well as the development process. You will write very little code for this lab, and instead work through a typical debugging process when working with a combination of hardware and software. At the end, you should be able to run the blink code we've given you on the R/Pi, and be comfortable moving any new code for future labs onto the Pi.

### Lab skills

  1. You will learn how to use the R/Pi dev toolchain.

  2. You will learn how to do differential debugging to find bugs.

  3. You will practice the unix terminal/git skills required for this class.

### Review Exercises

Most labs will have pre-lab review exercises to prepare you for the lab. If you read the readme and research what you don't understand, they shouldn't be hard to answer. Lab 0 will involve very little code, so the questions are more installation instructions for this all the tools you will need for this class.

#### Git

You will need to do the following before the first lab:

   - Install `git` on your laptop if you don't have it: we use `git`
     to push all assignments and code to you.  MacOS seems to ship with it, but you 
     might need to install the xcode command line tools with:

          % xcode-select --install
     
     For more details, try 
[this link] (https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

   - Once you have `git` installed, use it to clone (check out) the class repository:

          % git clone https://github.com/dddrrreee/cs49n-20spr.git

     If you have SSH keys configured, you can use this link (you will know if this is you):

          % git clone git@github.com:dddrrreee/cs49n-20spr.git  

     Pro tip: run this command in some sensible directory (e.g.,
     `~/class/`) and remember where you checked your repository out to! 
     Also, know how to find it.  We had a surprising (to me) number of
     people lose work because they did not do this.

     Pro tip: ***Do not download the class repository directly***!
     Direct download will be both tedious and overwrite any local changes
     you do later.

   - Bring a micro-SD card reader or adaptor if its not built-in to your laptop.
     The 
[CS107E guide on SD cards](http://cs107e.github.io/guides) is a great
     description (with pictures!).

   - Figure out where your SD card is mounted (usually on MacOS it is in
     `/Volumes/` and 
     on linux in `/media/yourusername/`).   Figure out how to copy files
     to the SD card from the command line using `cp`, which is much
     much faster and better than using a gui (e.g., you can put it in a
    `Makefile`, or use your shell to redo a command).  For me, 

           % cp kernel.img /media/engler/0330-444/
           % sync
 
     will copy the file `kernel.img` in the current directory to the 
     top level directory of the mounted SD card, the `sync` command forces
     the OS to flush out all dirty blocks to all stable media (SD card,
     flash drive, etc).  At this point you can pull the card out.

     Pro tip: ***do not omit either a `sync` or some file manager eject
     action*** if you do, parts of the copied file(s) may in fact not 
     be on the SD card.  (Why: writes to stable storage are slow, so
     the OS tends to defer them.)

   - For whatever shell (`tcsh` if linux, `bash` for mac, etc) you are using, figure out how to  
     edit your `PATH` variable so that you can install binary programs in a local
     `bin` directory and not have to constantly type out the path to them.  E.g.,

           % cd ~
           % mkdir bin 
           % cd bin 
           # pwd prints out the absolute path /home/engler/bin 
           % pwd         
               
     I would put `/home/engler/bin` in my `.tcshrc` file and then tell the shell
     to rescan the paths as follows:

           % source ~/.tcshrc

     For MacOS users, put the path to your `bin` directory in a .bashrc file (which you
     can put in your home directory or a specific class folder). Just run:

           % vim .bashrc

     When you add your path, make sure you include you default path or you may mess up your terminal.
     This looks like:

           % export PATH="$PATH:your/path/here:your/other/path/here"

     and source it the same way as the `.tcshrc`.

#### Unix Review

1) What file do you modify to edit your $PATH?

