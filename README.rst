**Pyramis** is a Domain-Specific language that enables you to specify multi-tier systems of variying complexities with minimal ambiguity:

#. **Specify** the nodes of your multi-tier system.
#. **Analyze** each node specification to ensure validity under Pyramis rules.
#. **Translate** each node specification to a C++ implementation.

⚙️ Installation
============
At present, Pyramis can only be installed from source.

PyPI (Python)
-------------
.. code-block:: bash

   pip install git+https://github.com/armaanchowfin/pyramis.git

⚡️ Quick start
===========

show them how to run the test example

🕹️ Using Pyramis
=================

First, **create your Pyramis specification**

   Please read our `Pyramis Keyword Reference <docs/pyramis-keywords.md>`_ for tips on writing Pyramis specifications

- Fix names and interfaces of individual nodes, define ``interfaces.json``.

- For each node, use Pyramis keywords to define a processing file ``node_name.dsl``. 

- UDFs, if any must be consolidated into a single ``udf.h``, ``udf.cpp`` pair. 

- Custom protocol headers, if any, must be in `utils/`

Next, navigate to the root directory of your project and **run Pyramis commands as necessary**

+-----------------------------------------------+-----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------+
| Task                                          | Command Line                                                                                        | Result                                                                      |
+===============================================+=====================================================================================================+=============================================================================+
| Validate Pyramis Specification                || ``$ pyramis translate NF_A``                                                                       || The Pyramis Compiler will generate an error-report for any irregularities  |
+-----------------------------------------------+-----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------+
| Build C++ Implementation                      || ``$ pyramis build NF_A``                                                                           || A set of .cpp and .h files will be generated along with a base Makefile.   |
+-----------------------------------------------+-----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------+
| Run C++ NFs                                   || ``$ pyramis run NF_A num_threads``                                                                 || Your NF specification is now a running NF instance                         |
+-----------------------------------------------+-----------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------+


💡 How Pyramis works
==================
   Please read our `Pyramis Developer Reference <docs/dev-docs.md>`_ for a more detailed treatment.
