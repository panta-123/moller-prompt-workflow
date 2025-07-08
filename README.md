# Snakemake Workflow for Moller Prompt Processing

This repository contains a Snakemake workflow designed to process Moller data, convert raw data to ROOT files, and generate plots. It leverages Apptainer (formerly Singularity) containers for reproducible execution.

Snakemake documentation: [https://snakemake.readthedocs.io/en/stable/](https://snakemake.readthedocs.io/en/stable/)

## Installation

To use this workflow, you need to have Snakemake installed on your system, along with Apptainer.

1.  **Install Snakemake:**
    Snakemake can be installed via Conda or pip.
    ```bash
    pip install snakemake
    ```

2.  **Install Apptainer:**
    Apptainer (or Singularity) is required to run the containerized steps of this workflow. Please refer to the official Apptainer documentation for installation instructions specific to your operating system: [https://apptainer.org/docs/user/latest/installation.html](https://apptainer.org/docs/user/latest/installation.html)

3.  **Clone the Repository:**
    Clone this Snakemake workflow repository to your local machine:

    ```bash
    git clone https://github.com/panta-123/moller-prompt-workflow.git
    cd moller-prompt-workflow
    ```

## Run the Workflow

Once Snakemake and Apptainer are installed and the repository is cloned, you can run the workflow from the root of the project directory.

```bash
snakemake --use-apptainer --apptainer-args "--bind /u,/cache,/volatile,/scratch,/work,/w"
```
