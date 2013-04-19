#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GL1_Primitives/GL1_Cube.o \
	${OBJECTDIR}/GL1_Primitives/GL1_Sphere.o \
	${OBJECTDIR}/GameStates/CubicGameState.o \
	${OBJECTDIR}/Gui.o \
	${OBJECTDIR}/IKArm.o \
	${OBJECTDIR}/IKLine.o \
	${OBJECTDIR}/Scenes/SceneBase.o \
	${OBJECTDIR}/Scenes/SceneCubicContainer.o \
	${OBJECTDIR}/Scenes/SceneGears.o \
	${OBJECTDIR}/Scenes/SceneIK.o \
	${OBJECTDIR}/Scenes/SceneMD5.o \
	${OBJECTDIR}/Scenes/SceneMorph.o \
	${OBJECTDIR}/Scenes/SceneParticleBase.o \
	${OBJECTDIR}/Scenes/SceneParticleFountain.o \
	${OBJECTDIR}/Scenes/SceneParticleRepelant.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/md5/Joint.o \
	${OBJECTDIR}/md5/JointFrame.o \
	${OBJECTDIR}/md5/Md5.o \
	${OBJECTDIR}/md5/Md5Frame.o \
	${OBJECTDIR}/md5/Mesh.o \
	${OBJECTDIR}/md5/Quaternion.o \
	${OBJECTDIR}/md5/Triangle.o \
	${OBJECTDIR}/md5/Vertex.o \
	${OBJECTDIR}/md5/Weight.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scarter_engine

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scarter_engine: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scarter_engine ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/GL1_Primitives/GL1_Cube.o: GL1_Primitives/GL1_Cube.cpp 
	${MKDIR} -p ${OBJECTDIR}/GL1_Primitives
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GL1_Primitives/GL1_Cube.o GL1_Primitives/GL1_Cube.cpp

${OBJECTDIR}/GL1_Primitives/GL1_Sphere.o: GL1_Primitives/GL1_Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/GL1_Primitives
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GL1_Primitives/GL1_Sphere.o GL1_Primitives/GL1_Sphere.cpp

${OBJECTDIR}/GameStates/CubicGameState.o: GameStates/CubicGameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/GameStates
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameStates/CubicGameState.o GameStates/CubicGameState.cpp

${OBJECTDIR}/Gui.o: Gui.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Gui.o Gui.cpp

${OBJECTDIR}/IKArm.o: IKArm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/IKArm.o IKArm.cpp

${OBJECTDIR}/IKLine.o: IKLine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/IKLine.o IKLine.cpp

${OBJECTDIR}/Scenes/SceneBase.o: Scenes/SceneBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneBase.o Scenes/SceneBase.cpp

${OBJECTDIR}/Scenes/SceneCubicContainer.o: Scenes/SceneCubicContainer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneCubicContainer.o Scenes/SceneCubicContainer.cpp

${OBJECTDIR}/Scenes/SceneGears.o: Scenes/SceneGears.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneGears.o Scenes/SceneGears.cpp

${OBJECTDIR}/Scenes/SceneIK.o: Scenes/SceneIK.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneIK.o Scenes/SceneIK.cpp

${OBJECTDIR}/Scenes/SceneMD5.o: Scenes/SceneMD5.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneMD5.o Scenes/SceneMD5.cpp

${OBJECTDIR}/Scenes/SceneMorph.o: Scenes/SceneMorph.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneMorph.o Scenes/SceneMorph.cpp

${OBJECTDIR}/Scenes/SceneParticleBase.o: Scenes/SceneParticleBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneParticleBase.o Scenes/SceneParticleBase.cpp

${OBJECTDIR}/Scenes/SceneParticleFountain.o: Scenes/SceneParticleFountain.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneParticleFountain.o Scenes/SceneParticleFountain.cpp

${OBJECTDIR}/Scenes/SceneParticleRepelant.o: Scenes/SceneParticleRepelant.cpp 
	${MKDIR} -p ${OBJECTDIR}/Scenes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scenes/SceneParticleRepelant.o Scenes/SceneParticleRepelant.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/md5/Joint.o: md5/Joint.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Joint.o md5/Joint.cpp

${OBJECTDIR}/md5/JointFrame.o: md5/JointFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/JointFrame.o md5/JointFrame.cpp

${OBJECTDIR}/md5/Md5.o: md5/Md5.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Md5.o md5/Md5.cpp

${OBJECTDIR}/md5/Md5Frame.o: md5/Md5Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Md5Frame.o md5/Md5Frame.cpp

${OBJECTDIR}/md5/Mesh.o: md5/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Mesh.o md5/Mesh.cpp

${OBJECTDIR}/md5/Quaternion.o: md5/Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Quaternion.o md5/Quaternion.cpp

${OBJECTDIR}/md5/Triangle.o: md5/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Triangle.o md5/Triangle.cpp

${OBJECTDIR}/md5/Vertex.o: md5/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Vertex.o md5/Vertex.cpp

${OBJECTDIR}/md5/Weight.o: md5/Weight.cpp 
	${MKDIR} -p ${OBJECTDIR}/md5
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/md5/Weight.o md5/Weight.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/scarter_engine

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
