CXX = g++
CXXFLAGS = -std=c++11

SOURCES = \
	Connector.cpp \
	ConnectorFactory.cpp \
	PostgresConnector.cpp \
	PostgresFactory.cpp \
	CsvConnector.cpp \
	CsvFactory.cpp \
	RestApiConnector.cpp \
	RestApiFactory.cpp \
	Transformation.cpp \
	DeduplicateStep.cpp \
	AggregateByRegionStep.cpp \
	TransformationRegistry.cpp \
	Pipeline.cpp \
	BatchPipeline.cpp \
	StreamingPipeline.cpp \
	RunCheckpoint.cpp \
	CheckpointManager.cpp \
	main.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = engine

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean