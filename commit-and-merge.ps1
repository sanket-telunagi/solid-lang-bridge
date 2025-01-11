# Define the branches
$branches = @("java", "c++", "python")
$mainBranch = "main"

# Define fixed files for the main branch
$fixedFiles = @(".gitignore", "ReadMe.md")

# Commit changes to each branch
foreach ($branch in $branches) {
    Write-Host "Switching to branch: $branch" -ForegroundColor Cyan
    git checkout $branch

    # Stage and commit changes
    Write-Host "Staging and committing changes for branch: $branch" -ForegroundColor Green
    git add .
    git commit -m "Updated $branch branch with relevant changes"
    git push origin $branch
}

# Switch to the main branch
Write-Host "Switching to main branch" -ForegroundColor Cyan
git checkout $mainBranch

# Merge each branch into main, keeping .gitignore and README.md fixed
foreach ($branch in $branches) {
    Write-Host "Merging $branch into $mainBranch, keeping fixed files intact" -ForegroundColor Green
    git merge --no-commit --no-ff $branch

    # Reset fixed files to their original state
    foreach ($file in $fixedFiles) {
        Write-Host "Resetting $file to its original state in $mainBranch" -ForegroundColor Yellow
        git checkout HEAD -- $file
    }

    # Commit the merge
    git commit -m "Merged $branch into $mainBranch, preserving fixed files"
}

# Push changes to the main branch
Write-Host "Pushing changes to main branch" -ForegroundColor Cyan
git push origin $mainBranch

Write-Host "All branches updated and merged into main branch successfully!" -ForegroundColor Green
