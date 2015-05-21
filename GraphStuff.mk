##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GraphStuff
ConfigurationName      :=Debug
WorkspacePath          := "/home/rik/STUFF/workspace/Test"
ProjectPath            := "/home/rik/STUFF/workspace/Test/GraphStuff"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rik
Date                   :=21/05/15
CodeLitePath           :="/home/rik/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GraphStuff.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(ObjectSuffix): ConsoleApplication2/BFSGraph.cpp $(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/BFSGraph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(DependSuffix): ConsoleApplication2/BFSGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(DependSuffix) -MM "ConsoleApplication2/BFSGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(PreprocessSuffix): ConsoleApplication2/BFSGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_BFSGraph.cpp$(PreprocessSuffix) "ConsoleApplication2/BFSGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(ObjectSuffix): ConsoleApplication2/DFSGraph.cpp $(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/DFSGraph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(DependSuffix): ConsoleApplication2/DFSGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(DependSuffix) -MM "ConsoleApplication2/DFSGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(PreprocessSuffix): ConsoleApplication2/DFSGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_DFSGraph.cpp$(PreprocessSuffix) "ConsoleApplication2/DFSGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(ObjectSuffix): ConsoleApplication2/Graph.cpp $(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/Graph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(DependSuffix): ConsoleApplication2/Graph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(DependSuffix) -MM "ConsoleApplication2/Graph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(PreprocessSuffix): ConsoleApplication2/Graph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_Graph.cpp$(PreprocessSuffix) "ConsoleApplication2/Graph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(ObjectSuffix): ConsoleApplication2/MyGraph.cpp $(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/MyGraph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(DependSuffix): ConsoleApplication2/MyGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(DependSuffix) -MM "ConsoleApplication2/MyGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(PreprocessSuffix): ConsoleApplication2/MyGraph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_MyGraph.cpp$(PreprocessSuffix) "ConsoleApplication2/MyGraph.cpp"

$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(ObjectSuffix): ConsoleApplication2/Node.cpp $(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/Node.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(DependSuffix): ConsoleApplication2/Node.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(DependSuffix) -MM "ConsoleApplication2/Node.cpp"

$(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(PreprocessSuffix): ConsoleApplication2/Node.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_Node.cpp$(PreprocessSuffix) "ConsoleApplication2/Node.cpp"

$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(ObjectSuffix): ConsoleApplication2/ShortestPaths.cpp $(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/ShortestPaths.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(DependSuffix): ConsoleApplication2/ShortestPaths.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(DependSuffix) -MM "ConsoleApplication2/ShortestPaths.cpp"

$(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(PreprocessSuffix): ConsoleApplication2/ShortestPaths.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConsoleApplication2_ShortestPaths.cpp$(PreprocessSuffix) "ConsoleApplication2/ShortestPaths.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


