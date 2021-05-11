This section explains how to setup your development environment and gives you some basic advice on how to contribute to the project.

## Table of contents

- [Table of contents](#table-of-contents)
- [IDE](#ide)
  - [Visual Studio Code](#visual-studio-code)
    - [Installation](#installation)
    - [Required Extensions](#required-extensions)
    - [Optional Extensions](#optional-extensions)
- [Project Documentation](#project-documentation)
  - [General](#general)
  - [Diagrams](#diagrams)
- [Coding rules](#coding-rules)
  - [Documentation with Doxygen](#documentation-with-doxygen)
- [Git](#git)
  - [Workflow](#workflow)
  - [Committing](#committing)

## IDE

### Visual Studio Code

I develop under VSC but development environments may be used.

#### Installation

Windows:

Download installer from [here](https://code.visualstudio.com/) and install.

Linux:

```sh
sudo snap install --classic code
```

#### Required Extensions

- [PlatformIO IDE](https://github.com/platformio/platformio-vscode-ide) : To compile, test and upload programs to Arduino (and other boards).

    ```sh
    code --install-extension platformio.platformio-ide
    ```

- [C/C++](https://github.com/Microsoft/vscode-cpptools) : Language support for VSC.

    ```sh
    code --install-extension ms-vscode.cpptools
    ```

#### Optional Extensions

Hererunder a list of useful extensions I use for this project:

- [Doxygen Documentation Generator](https://github.com/cschlosser/doxdocgen) : Handy extension to generated automatically a doxygen placeholder comment when typing `/**` before a function.

    ```sh
    code --install-extension cschlosser.doxdocgen
    ```

- [Github Extension](https://github.com/Microsoft/vscode-pull-request-github) : Useful to view issues and pull requests from the project repository directly inside VSC.

    ```sh
    code --install-extension GitHub.vscode-pull-request-github
    ```

- [PlantUML](https://github.com/qjebbs/vscode-plantuml) : Used to create and generate UML diagrams. This extension requires Java and [Graphviz](https://www.graphviz.org/download/) to be installed. I would also recommend to use the [SVG extension](https://github.com/lishu/vscode-svg2) to view generated diagrams that were exported as SVG.

    On Windows:

    ```sh
    choco install graphviz
    ```

    On Ubuntu:

    ```sh
    sudo apt install java
    sudo apt install graphviz
    ```

    On both:

    ```sh
    code --install-extension jebbs.plantuml
    code --install-extension jock.svg
    ```

- [Markdown All in One](https://github.com/yzhang-gh/vscode-markdown) : Markdown syntax highlighting, automatic table of content generation and shortcuts. I also recommend to install [Markdown Lint](https://github.com/DavidAnson/vscode-markdownlint) to verify if the Markdown syntax is correct and the [Enhanced Markdown preview](https://github.com/shd101wyy/vscode-markdown-preview-enhanced).

    ```sh
    code --install-extension yzhang.markdown-all-in-one
    code --install-extension DavidAnson.vscode-markdownlint
    code --install-extension shd101wyy.markdown-preview-enhanced
    ```

- [TODO Tree](https://github.com/Gruntfuggly/todo-tree) : To track `TODO` and `FIXME` comments in the code.

  ```sh
  code --install-extension gruntfuggly.todo-tree
  ```

## Project Documentation

### General

A good entry point to understand the overal software design of the robot:

TODO Add links to other pages

### Diagrams

Diagrams are created with [PlantUML](https://plantuml.com).

Documentation:

- [Class diagrams](https://plantuml.com/fr/class-diagram)

## Coding rules

### Documentation with Doxygen

The source code should be documentetd with Doxygen tags. Hereunder an example of a Doxygen file header:

```c++
/**
 * @file SharpDistSensorArray.h
 * @author Mike Margreve (mike.margreve@outlook.com)
 * @brief This library manages the 3 Sharp distance sensors on the robot
 * @version 1.0
 * @date 2020-04-25
 */
```

Functions are documented in a similar way:

```c++
/**
 * @brief Re-maps a number from one range to another (floating point variant).
 *
 * That is, a value of fromLow would get mapped to toLow,
 * a value of fromHigh to toHigh, values in-between to values in-between, etc.
 *
 * @param value the number to map.
 * @param fromLow the lower bound of the value’s current range.
 * @param fromHigh the upper bound of the value’s current range.
 * @param toLow the lower bound of the value’s target range.
 * @param toHigh the upper bound of the value’s target range.
 * @return The mapped value.
 */
float mapFloat(float value, float fromLow, float fromHigh, float toLow, float toHigh);
```

An exhaustive list of Doxygen tags can be found in the [documentation](https://www.doxygen.nl/manual/docblocks.html#cppblock).

## Git

Clone the repository:

```sh
git clone https://github.com/margrevm/trollbot.git
```

### Workflow

The project uses the *Gitflow* workflow for branch management. More information about how this works can be found in this [tutorial](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow).
  
Basically there are three types of branches:

- The `master` branch for releases.
- The `dev` branch for development which contains the current stable build (tested with TravisCI).
- `feature/<feature>` branches which are based on the `dev` branch and contain changes for each new feature. Once a feature is finished, it is merged to `dev`.

### Committing

- When committing, please add the reference of the corresponding issue `#XXX` to the message.
- Issues can be automatically closed with `close`, `closes`, `closed`, `fixes` or `fixed` keywords in the message.

More documentation about the Github issue management can be found on the [GitHub Blog](https://github.blog/2011-04-09-issues-2-0-the-next-generation/).

**Thanks for contributing!**
