import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing

process = cms.Process("temptest")

#process.source = cms.Source("EmptySource")
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring("myOutputFile.root")
    , skipEvents = cms.untracked.uint32(0)#options.skipEvents
    )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

#load our module
#module stuff = MyStuffProducer {}
#process.stuff=cms.EDProducer("MyStuffProducer") 

process.stuff = cms.EDProducer('temp_test'
    , reducedEBRecHitCollection = cms.InputTag('reducedEcalRecHitsEB')
    , photonCollection = cms.InputTag('slimmedPhotons')
    , integer_=cms.InputTag('integer')
    , value_=cms.InputTag('value')
    , vecvalues_=cms.InputTag('vecvalues')
    , tempgenParticles_=cms.InputTag('tempgenParticles')
    )

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("myoutput1.root")#options.outputFile
    )

#make sure our module is called every event
process.p = cms.Path(process.stuff)

#just to see that something is happening
#service = cms.Tracer()
