#Tennessee Bonner
#tcb150030@utdallas.edu
#Project 5
#CS3377.501
#This is the makefile for the CDK display matrix that also can produce a backup file

CXX = g++
CXXFLAGS = -Wall -g 
CPPFLAGS = -I/scratch/perkins/include

LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses 

PROJECTNAME = tcb150030.Project6

EXECFILE = project6

OBJS = project6.o


all: $(EXECFILE)


clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*


$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)


backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "'pwd'"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
