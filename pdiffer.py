import os.path
import ctypes

compare_args_module = ctypes.cdll.LoadLibrary(
    os.path.abspath(os.path.join(os.path.dirname(__file__), 'CompareArgs.so')))

metric_module = ctypes.cdll.LoadLibrary(
    os.path.abspath(os.path.join(os.path.dirname(__file__), 'Metric.so')))



compare_args_module.new_RGBAImage.argtypes = [ctypes.c_int, ctypes.c_int,
                                                  ctypes.c_void_p]
metric_module.Yee_Compare.restype = ctypes.c_bool


def compare_images(img_a, img_b, LuminanceOnly=None, FieldOfView=None,
                   Gamma=None, Luminance=None, ThresholdPixels=None):
    height_a, width_a, depth = img_a.shape
    height_b, width_a, depth = img_b.shape

    cargs = compare_args_module.new_CompareArgs()
    img_1 = compare_args_module.new_RGBAImage(height_a, width_a, img_a.ctypes.data)
    img_2 = compare_args_module.new_RGBAImage(height_b, width_a, img_b.ctypes.data)
    compare_args_module.set__ImgA(cargs, img_1)
    compare_args_module.set__ImgB(cargs, img_2)

    #Actually compare
    res = metric_module.Yee_Compare(cargs)

    #TODO: Figure out what images need to be deleted
    compare_args_module.del_CompareArgs(cargs)

    return res
    

if __name__ == '__main__':
    import cv2
    img_a = cv2.imread(os.path.expanduser('~/Desktop/Screenshot.png'))
    img_b = cv2.imread(os.path.expanduser('~/Desktop/Screenshot.png'))
    print "output", compare_images(img_a, img_b)
