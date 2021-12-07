# 矩阵乘法（Opencv）

- 加法

  ~~~c++
  I = I1 + I2;
  add(I1, I2, dest, mask, dtype);
  scaleAdd(I1, scale, I2, dest); // dest = I1*scale + I2
  addWeighted();
  ~~~

- 减法

  ~~~C++
  absdiff(I1, I2, dest, mask, dtype);
  A-B;
  -A;
  substract(I1, I2, dest);
  ~~~

- 乘法

  ~~~C++
  I = I.mul(I);       // 点乘I.mul(I, 3); -> I=3*I^2
  Mat C = A.mul(5/B); // == divide(A,B,C,5)
  A*B;                // 矩阵相乘
  I = alpha * I;
  A-s;
  s-A；
  Mat::cross(Mat);    // 三维向量的叉积
  Mat::dot(Mat);      // 2个向量(或矩阵)点乘的结果
  pow(I, double p, dest); // 如何p是整数，dst(I)=src(I)^p;其他|src(I)|^p
  ~~~

- 除法

  ~~~c++
  divide(I1, I2, dest, scale, int dtype=-1); // dest = saturate_cast(I1*scale/I2)
  A/B;       // 点乘
  alpha/A;   // 点乘
  ~~~

- 转换

  ~~~C++
  I.convertTo(I1,CV_32F);
  A.t();
  flip(I,dst,int flipCode);//flipCode=0是上下翻转，
                           //        >0时左右翻转,
                           //        <0时一起来
  sqrt(I,dst);
  cvtColor(I,dst,int code,int dstCn=0);
  resize(src, dst, Size dsize, double fx = 0, double fy = 0, int interpolation = INTER_LINEAR ); // fx,fy:scale factor
  ~~~

- 其他

  ~~~C++
  Scalar s=sum(I);                          // 各通道求和
  norm();                                   
  countNonZero();
  trace();
  determinant();
  repeat();
  countNonZero();
  Scalar m=mean(I);                                   //各通道求平均
  Mat RowClone=C.row(1).clone();                      //复制第2行
  addWeight(I1,alpha,I2,beta,gamma,dst,int dtype=-1); //dst=saturate(alpha*I1+beta*I2+gamma);dtype是dst的深度
  meanStdDev();                                       // calculates the mean and the standard deviation
  calcCovarMatrix();
  ~~~

- 运算符

  ~~~C++
  log10();
  exp(I,dst);//dst=exp(I);计算每个数组元素的指数
  log(I,dst);//如果Iij!=0;则dstij=log(|Iij|)
  randu(I,Scalar::all(0),Scalar::all(255)); // 返回一个随机矩阵
  Mat::t()                                  // 转置
  Mat::inv(int method=DECOMP_LU);           // 求逆。
                                            // method=DECOMP_CHOLESKY(专门用于对称，速度是LU的2倍),
                                            //        DECOMP_SVD
  invert(I1,dst,int method=DECOMP_LU);      //用法同上
  MatExpr abs(Mat);                         //求绝对值
  // 👇这里cmpop表示>,>=,==,!=,<=,<等，结果是CV_8UC1的mask的0或255
  A cmpop B;                 // CMP_EQ CMP_GT 
  A compop alpha;            // CMP_GE CMP_LT 
  alpha cmpop A;             // CMP_LE CMP_NE 
  // 👆这里cmpop表示>,>=,==,!=,<=,<等，结果是CV_8UC1的mask的0或255
  // 👇按位运算：
  A logicop B;
  A logicop s;
  s logicop A;
  ~A;
  // 👆这里logicop代表&,|,^
  bitwise_not(I,dst,mask);  //inverts所有的队列
  bitwise_and();
  bitwise_or();
  bitwise_xor();
  // 👇都返回MatExpr,返回的dst和A的类型一样
  min(A,B);
  min(A,alpha);
  max(A,B);
  max(A,alpha);
  // 👆都返回MatExpr,返回的dst和A的类型一样
  double determinant(Mat);                             //行列式
  bool eigen(I1,dst,I,int…);                           //得到特征值向量dst和对应特征值的特征向量
  void eigenNonSymmetric(I1, destEigenValues, eigenvectors);
  minMaxLoc(I1,&minVal,&maxVal,Point *minLoc=0,Point* MaxLoc=0,mask);
  ~~~

- 初始化

  ~~~C++
  Mat I(img,Rect(10,10,100,100));       //用一块地方初始化。
  Mat I=img(Range:all(),Range(1,3));    //所有行，1~3列
  Mat I=img.clone();                    //完全复制
  img.copyTo(I);                        //传递矩阵头
  Mat I(2,2,CV_8UC3,Scalar(0,0,255)); 
  Mat E=Mat::eye(4,4,CV_64F);           //对角矩阵
  Mat O=Mat::ones(2,2,CV_32F);          //全一矩阵
  Mat Z=Mat::zeros(3,3,CV_8UC1);        //全零矩阵
  Mat C=(Mat_<double>(2,2)<<0,-1,2,3);  //如果是简单矩阵的初始化
  // 👇都只是创建个头
  Mat::row(i);
  Mat::col(j);
  Mat::rowRange(start,end);
  Mat::colRange(start,end);
  // 👆都只是创建个头
  Mat::diag(int d);                     // d=0是是主对角线，d=1是比主低的对角线,d=-1….
  static Mat Mat::diag(const Mat& matD)
  Mat::setTo(Scalar &s);                // 以s初始化矩阵
  Mat::push_back(Mat);                  // 在原来的Mat的最后一行后再加几行
  Mat::pop_back(size_t nelems=1);       // 移出最下面几行
  ~~~

- 矩阵读取与修改

  ~~~C++
  Mat::total();                         // 返回一共的元素数量
  size_t Mat::elemSize();               // 返回元素的大小:CV_16SC3–>3*sizeof(short)–>6
  size_t Mat::elemSize1();              // 返回元素一个通道的大小CV_16SC3–>sizeof(short)–>2
  int Mat::type();                      // 返回他的类型CV_16SC3之类
  int Mat::depth();                     // 返回深度:CV_16SC3–>CV_16S
  int Mat::channels();                  // 返回通道数
  size_t Mat:step1();                   // 返回一个被elemSize1()除以过的step
  Size Mat::size();                     // 返回Size(cols,rows);
                                        // 如果大于2维，则返回(-1,-1)，都是先宽再高的
  bool Mat::empty();                    // 如果没有元素返回1,即Mat::total()==0或者Mat::data==NULL
  uchar *Mat::ptr(int i=0);             // 指向第i行
  Mat::at(int i)(int i,int j)(Point pt)(int i,int j,int k);
  // -----RNG随机类:------
  theRNG();                                         // 返回一个默认构造的RNG类的对象 theRNG()::fill(...)
  float RNG::uniform(float a,float b);
  double RNG::gaussian(double sigma);
  RNG::fill(I,int distType,Mat low,Mat up);         // 用随机数填充
  randu(I,low,high);                                // Uniform
  randn(I,Mat mean,Mat stddev);                     // Normal
  reduce(I,dst,int dim,int reduceOp,int dtype=-1);  // 矩阵缩成向量
  setIdentity(dst,Scalar &value=Scalar(1));         // 把对角线替换为value 效果等同：Mat A=Mat::eye(4,3,CV_32F)*5;
  ~~~

- 较复杂运算

  gemm(I1,I2,alpha,I3,beta,dst,int flags=0);        // 一个广义的矩阵乘法操作: I1至少是浮点型,I2同I1,flags用来转置
  gemm(I1,I2,alpha,I3,beta,dst,GEMM_1_T,GEMM_3_T);  // –>dst=alpha*I1.t()*I2+beta*I3.t();可用此完全代替此函数

  dct(I,dst,int flags=0);//DCT变换，1维、2维的矩阵;flags=DCT_INVERSE,DCT_ROWS
  idct,dft,idft

  dct, idct
  正、逆离散余弦变换，idct同dct(src, dst, flags | DCT_INVERSE)
  dft, idft
  正、逆离散傅立叶变换, idft同dft(src, dst, flags | DTF_INVERSE)

  LUT
  查表变换
  getOptimalDFTSize
  返回一个优化过的DFT大小
  mulSpecturms
  两个傅立叶频谱间逐元素的乘法
      
  getConvertElem,extractImageCOI,LUT
  magnitude(x,y,dst);//I1,I2都是1维向量,dst=sqrt(x(I)^2+y(I)^2);
  MulSpectrums(I1,I2,dst,flags);傅里叶
  PCA,SVD,solve,transform,
  Mat mask=src<0;这样很快建立一个mask了

  ~~~C++
  mulTransposed(I,dst,bool aTa,Mat delta=noArray(),double scale=1,int rtype=-1); // 矩阵和它自己的转置相乘
                                                                                 //I是1通道的,和gemm不同,他可用于任何类型。
                                                                  //如果aTa=flase时,dst=scale*(I-delta).t()*(I-delta);
                                                                  //如果是true,dst=scale*(I-delta)(I-delta).t();
  cartToPolar();        // 笛卡尔坐标转到极坐标
  polarToCart();        // 极坐标转到笛卡尔坐标
  completeSymm(M,bool lowerToUpper=false);    // 矩阵上下三角拷贝   
                                              // 当lowerToUpper=true时Mij=Mji(i<j);当为flase时,Mij=Mji(i>j)
  convertScaleAbs(I,dst,alpha,beta);          // 先缩放元素再取绝对值，最后转换格式为8bit型
  dst=saturate_cast<uchar>(|alpha*I+beta|);
  inRange(I1,I_low,I_up,dst);  //dst是CV_8UC1,在2者之间就是255
  checkRange()；
  split();                  // 多通道矩阵分解成多个单通道矩阵
  merge(vector<Mat>,Mat);   // 把多个Mat组合成一个和split相反
  norm(…);                  // 求范数，1-范数、2-范数、无穷范数；当src2木有时,norm可以计算出最长向量、向量距离和、向量距离和的算术平方根
  solve();                  // 求解1个或多个线性系统或者求解最小平方问题(least-squares problem)
  solveCubic();             // 解3次方程
  solvePoly();              // 解n次方程
  sort();
  sortIdx();                // 为矩阵的每行或每列元素排序
  mixChannels();            // 矩阵间通道拷贝  对某个通道进行各种传递
  randShuffle();            // 随机打乱一个一维向量的元素顺序
  repeat();                 //矩阵拷贝的时候指定按x/y方向重复
  ~~~

- END