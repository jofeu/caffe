#ifndef reference_layers_h__
#define reference_layers_h__

#include "caffe/caffe.hpp"

// fake references to caffe layer registrars because static linking
// removes unreferenced layers

#define ALL_CAFFE_LAYERS \
	CAFFE_LAYER(AbsVal) \
	CAFFE_LAYER(Accuracy) \
	CAFFE_LAYER(ArgMax) \
	CAFFE_LAYER(BNLL) \
	CAFFE_LAYER(Concat) \
	CAFFE_LAYER(ContrastiveLoss) \
	CAFFE_LAYER(Data) \
	CAFFE_LAYER(Deconvolution) \
	CAFFE_LAYER(Dropout) \
	CAFFE_LAYER(DummyData) \
	CAFFE_LAYER(Eltwise) \
  CAFFE_LAYER(Embed) \
	CAFFE_LAYER(EuclideanLoss) \
	CAFFE_LAYER(Exp) \
  CAFFE_LAYER(Filter) \
	CAFFE_LAYER(Flatten) \
	CAFFE_LAYER(HDF5Data) \
	CAFFE_LAYER(HDF5Output) \
	CAFFE_LAYER(HingeLoss) \
	CAFFE_LAYER(Im2col) \
	CAFFE_LAYER(ImageData) \
	CAFFE_LAYER(InfogainLoss) \
	CAFFE_LAYER(InnerProduct) \
  CAFFE_LAYER(Log) \
	CAFFE_LAYER(LRN) \
	CAFFE_LAYER(MemoryData) \
	CAFFE_LAYER(MultinomialLogisticLoss) \
	CAFFE_LAYER(MVN) \
	CAFFE_LAYER(Power) \
  CAFFE_LAYER(PReLU) \
  CAFFE_LAYER(Reduction) \
  CAFFE_LAYER(Reshape) \
	CAFFE_LAYER(SigmoidCrossEntropyLoss) \
	CAFFE_LAYER(Silence) \
	CAFFE_LAYER(Slice) \
	CAFFE_LAYER(SoftmaxWithLoss) \
	CAFFE_LAYER(Split) \
  CAFFE_LAYER(SPP) \
	CAFFE_LAYER(Threshold) \
  CAFFE_LAYER(Tile) \
	CAFFE_LAYER(WindowData) \
	CAFFE_LAYER(Convolution) \
	CAFFE_LAYER(Pooling) \
	CAFFE_LAYER(ReLU) \
	CAFFE_LAYER(Sigmoid) \
	CAFFE_LAYER(Softmax) \
	CAFFE_LAYER(TanH) 


namespace caffe 
{
	#define CAFFE_LAYER(type) \
		extern LayerRegisterer<float>  g_creator_f_##type; \
		extern LayerRegisterer<double> g_creator_d_##type;
	ALL_CAFFE_LAYERS
	#undef CAFFE_LAYER

	void this_is_never_called()
	{
		#define CAFFE_LAYER(type) \
			memset(&g_creator_f_##type, 0, sizeof(g_creator_f_##type)); \
			memset(&g_creator_d_##type, 0, sizeof(g_creator_d_##type));
		ALL_CAFFE_LAYERS
		#undef CAFFE_LAYER
	}
}

#endif // reference_layers_h__
