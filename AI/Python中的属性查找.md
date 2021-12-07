# Python中的属性查找

- property动态属性

- \__get_attr__: 在找不到属性时被调用

  \__get_attribute__: 一般不被重写，class.attr时无条件进入

- 一个类只要实现下面任意方法就将其称为 属性描述符

​		\_\_get\_\_,         \_\_set\_\_,           \__delete__

​		实现\_\_get\_\_和\_\_set\_\_方法的叫做 数据描述符

​	   只实现\_\_get\_\_方法的叫做 非数据描述符

​       **查找顺序**：

​		如果user是某个类的实例， 那么user.age（以及等价的getattr(user, "age")）

​		

- 

  

  

  

  

  

  

  ~~~python
  ~~~

  