import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing

process = cms.Process("FramesProducer")

#process.source = cms.Source("EmptySource")
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/s/schaudha/public/CMSSW_10_6_8/src/demo/DoublePhotonPt10To100_pythia8_ReAOD_PU2017_MINIAODSIM.root")
    , skipEvents = cms.untracked.uint32(0)#options.skipEvents
    )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#load our module
#module stuff = MyStuffProducer {}
#process.stuff=cms.EDProducer("MyStuffProducer") 

process.stuff = cms.EDProducer('MyStuffProducer'
    , reducedEBRecHitCollection = cms.InputTag('reducedEcalRecHitsEB')
    , photonCollection = cms.InputTag('slimmedPhotons'))

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("myoutput1.root")#options.outputFile
    )

#make sure our module is called every event
process.p = cms.Path(process.stuff)

#just to see that something is happening
#service = cms.Tracer()
