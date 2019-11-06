You'll likely forget, but if at any point you need guides, the ones for
cs107e are a good place to look:
   - [CS107E repo] (http://cs107e.github.io/guides/)

You will need to do the following before the first lab:

   - Install `git` on your laptop: we use `git` to push all assignments and code to
     you.

   - Use `git` to clone (check out) the class repository.  

     Pro tip: remember where you checked your repository out to!   Also, know how to 
     find it.

     Pro tip: ***Do not download the class repository directly****!
     Direct download will be both tedious and overwrite any local changes
     you do.

   - Bring a micro-SD card reader or adaptor if its not built-in to your laptop.
     SD cards are described: [SD](http://cs107e.github.io/guides) for a

   - Figure out where your SD card is mounted (usually on MacOS it is in
     `/Volumes` and
     on linux in `/media/yourusername/`).   Figure out how to copy files
     to the SD card from the command line using `cp`, which is much
     much faster and better than using a gui (e.g., you can put it in a
     makefile, or use your shell to redo a command).  For me, 

        cp kernel.img /media/engler/0330-444/
        sync
 
     will copy the file in `kernel.img` in the current directory to the top level
     of the SD card, the `sync` command forces the OS to flush out all dirty blocks
     to the stable media (SD card, flash drive, etc).  At this point you can pull
     the card out.

   - For whatever shell (`tcsh`, `bash`, etc) you are using, figure out how to 
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

Nice-haves:

   - Figure out how to "tab complete" in your shell.  This gives you
     a fast(er) way to list out files and run things.  We'll show this,
     but you can google.

   - Figure out how to use tags.  Both `emacs` or `vim` support "tags",
     which use keyboard shortcuts to essentially treat identifiers as urls
     and navigate to the definitions of structures, functions, variables.
     This makes understanding code ***much much*** faster and easier.

   - Longer term: eliminate as much mouse usage as you can; especially
     eliminate screen switching.  Ideally you'll have your code in one
     window, the compilation in another on the same screen and switch back
     and forth between these without lifting your hands off the keyboard.

     The single biggest productivity slowdown I see in stanford undergrads
     (grads too) is the slow, laborious use of taking their hand off
     a keyboard, moving a mouse, clicking, switchin screens, clicking
     on something else, switching back, etc.   You don't realize how
     much this will cripple you until you watch someone who writes
     code well and compare how slow you move in comparison.  Plus,
     this switching screens means you lose context, you move slowly,
     you distrupt *flow*, which is basically the only real way you can
     get significant, effective work done..  Any time you move the mouse,
     you're not doing work.  Do what you can to stop this.

   - Install `gdb` if you can --- it makes things easier in other classes
     (e.g., you can do a backtrace after a crash to figure out where the
     code was) and for this class let you answer simple code questions
     quickly.
